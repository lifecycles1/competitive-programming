
# this files consists of 3 javascript solutions


# The city ordinance in BoxCity requires that all buildings be rectangles that lie flat along the ground. 
# All the information about a particular building is contained in 3 numbers:

# left: the x coordinate of the left side of the building,
# width: the width of the building,
# height: the height of the building.

# The skyline is a list of adjacent rectangular strips, and represents the collective outline of all the 
# buildings in BoxCity.

# Each strip is represented as (left, height) as defined above. We don't need the width of the strip, as this 
# is determined by the left side of the next strip. At the right edge of the city, there will be an infinitely 
# small strip (x, 0). Strips should be the minimum height possible.

# Given the list of buildings buildings, where each building is represented by an array of three elements 
# [left, width, height], return the skyline as a list of strips, where each strip is represented by an array 
# of two elements [left, height].

# For buildings = [[2, 3, 6]], the output should be
# solution(buildings) = [[2, 6], [5, 0]]





# JavaScript solution 1

# function solution(buildings) {
#   const skyline = [];
#   const heap = new Heap();
#   const insertedBuildings = new Set();
#   let currentXCoord = buildings[0][0];
#   let buildingIndex = 0;

#   const maxXCoord = Math.max(
#     ...buildings.map((building) => {
#       return building[0] + building[1];
#     })
#   );
#   while (buildingIndex < buildings.length && currentXCoord < maxXCoord) {
#     const currentBuilding = buildings[buildingIndex];
#     const endOfCurrentBuilding = currentBuilding[0] + currentBuilding[1];
#     const nextBuilding = buildingIndex !== buildings.length - 1 ? buildings[buildingIndex + 1] : [maxXCoord, 0, 0];

#     if (!insertedBuildings.has(buildingIndex)) {
#       heap.insert(currentBuilding[2], endOfCurrentBuilding);
#       insertedBuildings.add(buildingIndex);
#     }

#     while (heap.max() && heap.max().validUpToXCoord <= currentXCoord) {
#       heap.extractMax();
#     }

#     const maxNode = heap.max();
#     const bound = maxNode ? maxNode.validUpToXCoord : Infinity;
#     const nextBoundary = Math.min(bound, nextBuilding[0]);

#     if (!maxNode) {
#       skyline.push([currentXCoord, 0]);
#     } else if (skyline.length === 0 || skyline[skyline.length - 1][1] !== maxNode.height) {
#       skyline.push([currentXCoord, maxNode.height]);
#     }

#     if (nextBoundary === nextBuilding[0]) buildingIndex += 1;
#     currentXCoord = nextBoundary;
#   }

#   skyline.push([maxXCoord, 0]);
#   return skyline;
# }

# function Heap() {
#   this._heap = [];
# }

# Heap.prototype.max = function () {
#   return this._heap[0];
# };

# Heap.prototype.extractMax = function () {
#   if (this._heap.length === 0) return null;

#   const tempHeight = this._heap[0].height;
#   const tempValidUpTo = this._heap[0].validUpToXCoord;

#   const tempHeightEnd = this._heap[this._heap.length - 1].height;
#   const tempValidUpToEnd = this._heap[this._heap.length - 1].validUpToXCoord;

#   this._heap[0] = { height: tempHeightEnd, validUpToXCoord: tempValidUpToEnd };

#   this._heap[this._heap.length - 1] = { height: tempHeight, validUpToXCoord: tempValidUpTo };

#   const temp = this._heap.pop();
#   if (this._heap.length === 0) return temp;

#   let currentIndex = 0;
#   let leftChildIndex = 2 * currentIndex + 1;
#   let rightChildIndex = 2 * currentIndex + 2;

#   while (this._heap[leftChildIndex] || this._heap[rightChildIndex]) {
#     let currNode = this._heap[currentIndex];
#     let maxNode = this._heap[currentIndex];
#     let maxIndex = currentIndex;

#     if (this._heap[leftChildIndex] && this._heap[leftChildIndex].height > maxNode.height) {
#       maxNode = this._heap[leftChildIndex];
#       maxIndex = leftChildIndex;
#     }

#     if (this._heap[rightChildIndex] && this._heap[rightChildIndex].height > maxNode.height) {
#       maxNode = this._heap[rightChildIndex];
#       maxIndex = rightChildIndex;
#     }

#     if (currNode === maxNode) {
#       break;
#     } else {
#       let tempHeightCurr = currNode.height;
#       let tempValCurr = currNode.validUpToXCoord;

#       currNode.height = maxNode.height;
#       currNode.validUpToXCoord = maxNode.validUpToXCoord;

#       maxNode.height = tempHeightCurr;
#       maxNode.validUpToXCoord = tempValCurr;

#       currentIndex = maxIndex;

#       leftChildIndex = 2 * currentIndex + 1;
#       rightChildIndex = 2 * currentIndex + 2;
#     }
#   }

#   return temp;
# };

# Heap.prototype.size = function () {
#   return this._heap.length;
# };

# Heap.prototype.insert = function (height, validUpToXCoord) {
#   const node = { height, validUpToXCoord };
#   this._heap.push(node);

#   let currentIndex = this.size() - 1;
#   let parentIndex = Math.ceil(currentIndex / 2) - 1;

#   while (currentIndex > 0 && this._heap[currentIndex].height > this._heap[parentIndex].height) {
#     const tempHeight = this._heap[currentIndex].height;
#     const tempValidUpTo = this._heap[currentIndex].validUpToXCoord;

#     const tempHeightPar = this._heap[parentIndex].height;
#     const tempValidUpToPar = this._heap[parentIndex].validUpToXCoord;

#     this._heap[currentIndex] = {
#       height: tempHeightPar,
#       validUpToXCoord: tempValidUpToPar,
#     };

#     this._heap[parentIndex] = {
#       height: tempHeight,
#       validUpToXCoord: tempValidUpTo,
#     };

#     currentIndex = parentIndex;
#     parentIndex = Math.ceil(currentIndex / 2) - 1;
#   }
# };




# JavaScript solution 2


# function solution(buildings) {
#   /* This algorithm builds a linked list to store the current skyline structure
#    * and compares with the next element.
#    * The new buildings not compared with all of the previous processed.
#    * The comparison starts from first visible building part, where
#    *   visible_part.right > new building.x
#    *
#    * It's enough fast for large list.
#    * Bechmark:
#    *    on cf environment: with 1 million items:  414ms
#    *    on local machine:  with 1 million items:  240ms
#    *                       with 5 million items: 1467ms
#    *
#    * buildings = [];
#    * for (i = 0; i < 1000000; i++)
#    *     buildings[i] = [i, Math.random() * 1e6 + 1 | 0, Math.random() * 1e6 + 1 | 0]
#    * console.log(buildings);
#    * console.time("time");
#    * console.log(solution(buildings));
#    * console.timeEnd("time");
#    */
#   list = { l: -1, r: 1e9, h: 0, n: null, p: null };
#   curr = list;

#   for (i in buildings) {
#     [l, w, h] = buildings[i];
#     node = { l: l, r: l + w, h: h, n: null, p: null };
#     while (curr.n && curr.n.r < l) curr = curr.n;
#     last = curr;
#     while (node) {
#       if (last.r < node.l || (last.r == node.l && last.h != node.h)) {
#         //      -----            -----
#         // -----N   N      ----- +---+
#         // L   L+---+  or  L   L +---+
#         // L   LN   N      L   L N   N
#         last = last.n;
#       } else if (last.l > node.r || (last.l == node.r && last.h != node.h)) {
#         //      -----            -----
#         // -----L   L      ----- +---+
#         // N   N+---+  or  N   N +---+
#         // N   NL   L      N   N L   L
#         last.p.n = node;
#         node.p = last.p;
#         node.n = last;
#         last.p = node;
#         node = false;
#       } else if (last.l <= node.l && last.r >= node.r && last.h >= node.h) {
#         // ----=====----      -=====----      -=====-      ----=====-
#         // L   +---+   L  or  L+---+   L  or  L+---+L  or  L   +---+L
#         // L   N   N   L      LN   N   L      LN   NL      L   N   NL
#         node = false;
#       } else if (last.l >= node.l && last.r <= node.r && last.h <= node.h) {
#         // ----=====----      -=====----      -=====-      ----=====-
#         // N   +---+   N  or  N+---+   N  or  N+---+N  or  N   +---+N
#         // N   L   L   N      NL   L   N      NL   LN      N   L   LN
#         last.p.n = last.n;
#         last.n.p = last.p;
#         last = last.n;
#       } else if (last.h == node.h) {
#         // ----=====----      ----=====----
#         // N   L   N   L  or  L   N   L   N
#         // N   L   N   L      L   N   L   N
#         if (last.l < node.l) node.l = last.l;
#         if (last.r > node.r) node.r = last.l;
#         last.p.n = last.n;
#         last.n.p = last.p;
#         last = last.n;
#       } else if (last.h < node.h) {
#         if (last.l < node.l && last.r > node.r) {
#           //     -----
#           // ----N   N----
#           // L   N   N   L
#           tmp = { l: node.r, r: last.r, h: last.h, n: last.n, p: node };
#           last.r = node.l;
#           last.n ? (last.n.p = tmp) : 0;
#           last.n = node;
#           node.n = tmp;
#           node.p = last;
#           node = false;
#         } else if (last.l < node.l) {
#           //     ---------        ------
#           // ----N----   N    ----N----N
#           // L   N   L   N or L   N   LN
#           last.r = node.l;
#           last = last.n;
#         } else {
#           // ------          ---------
#           // N----N----  or  N   ----N----
#           // NL   N   L      N   L   N   N
#           last.p.n = node;
#           node.p = last.p;
#           node.n = last;
#           last.p = node;
#           last.l = node.r;
#           node = false;
#         }
#       } else {
#         if (last.l > node.l && last.r < node.r) {
#           //     -----
#           // ----L   L----
#           // N   L   L   N
#           tmp = { l: node.l, r: last.l, h: node.h, n: last, p: last.p };
#           last.p.n = tmp;
#           last.p = tmp;
#           node.l = last.r;
#         } else if (last.l <= node.l) {
#           // ------          ---------
#           // L----L----  or  L   ----L----
#           // LN   L   N      L   N   L   N
#           node.l = last.r;
#         } else {
#           //     ---------        ------
#           // ----L----   L    ----L----N
#           // N   L   N   L or N   L   NN
#           last.p.n = node;
#           node.p = last.p;
#           node.n = last;
#           last.p = node;
#           node.r = last.l;
#           node = false;
#         }
#       }
#     }
#   }
#   tmp = list;
#   ret = [];
#   r = 1e9;
#   while (tmp) {
#     if (tmp.l > r) ret.push([r, 0]);
#     if (tmp.l >= 0) ret.push([tmp.l, tmp.h]);
#     r = tmp.r;
#     tmp = tmp.n;
#   }
#   return ret;
# }

# /*
# buildings = [];
# for (i = 0; i < 1000000; i++)
#    buildings[i] = [i, Math.random() * 1e6 + 1 | 0, Math.random() * 1e6 + 1 | 0]
# console.log(buildings);
# console.time("time");
# console.log(solution(buildings));
# console.timeEnd("time");
# */



# JavaScript solution 3

# solution = (b) => {
#   r = [];
#   p = [];
#   m = { 0: 1 };

#   b.map(([l, w, h]) => p.push([l, h], [l + w, -h]));
#   p.sort(([x, i], [y, j]) => x - y || j - i);
#   i = j = 0;
#   p.map(([x, y]) => {
#     y > 0 ? (m[y] = -~m[i < y ? (i = y) : y]) : !--m[-y] && (delete m[-y], j == -y ? (i = Object.keys(m).pop()) : 0);
#     i != j && r.push([x, i]);
#     j = i;
#   });

#   return r;
# };
