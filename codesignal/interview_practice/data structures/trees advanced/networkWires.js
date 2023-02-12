////////////////////////// 1st solution //////////////////////////
////////////////////////// 1st solution //////////////////////////
////////////////////////// 1st solution //////////////////////////
////////////////////////// 1st solution //////////////////////////
////////////////////////// 1st solution //////////////////////////
////////////////////////// 1st solution //////////////////////////
////////////////////////// 1st solution //////////////////////////
////////////////////////// 1st solution //////////////////////////
////////////////////////// 1st solution //////////////////////////
////////////////////////// 1st solution //////////////////////////
////////////////////////// 1st solution //////////////////////////
////////////////////////// 1st solution //////////////////////////
////////////////////////// 1st solution //////////////////////////
////////////////////////// 1st solution //////////////////////////
////////////////////////// 1st solution //////////////////////////

//********************** PRIM'S ALGORITHM *******
function solution(n, wires) {
  let treeMap = new BinaryMinHeapMap(),
    map = Array.from({ length: n }, (v, i) => {
      treeMap.add(i, Infinity);
      return [];
    }),
    MST = 0;
  wires.map(([vertex1, vertex2, length]) => {
    map[vertex1][vertex2] = map[vertex2][vertex1] = length;
  });

  treeMap.set(0, 0);
  while (treeMap.getSize()) {
    let currentNode = treeMap.extractMin(),
      currentVertex = currentNode.vertex,
      currentDistance = currentNode.data;
    //If the current distance === Infinity
    //It means that this vertex belongs to a whole new part of connected nodes
    //Just set distance to 0 and repeat the process
    MST += currentDistance === Infinity ? 0 : currentDistance;
    for (let nextVertex = 0; nextVertex < n; nextVertex++) {
      if (treeMap.has(nextVertex) && map[currentVertex][nextVertex] !== undefined) {
        treeMap.set(nextVertex, Math.min(treeMap.get(nextVertex).data, map[currentVertex][nextVertex]));
      }
    }
  }
  return MST;
}

function BinaryMinHeapMap() {
  let heap = [];
  let map = new Map();
  function Node(vertex, data) {
    this.vertex = vertex;
    this.data = data;
  }
  //swap to position in the heap, update vertex position
  //Update the position of two vertex in 2 two positions
  function swap(pos1, pos2) {
    const vertex1 = heap[pos1].vertex;
    const vertex2 = heap[pos2].vertex;
    const tmp = heap[pos1];
    map.set(vertex1, pos2);
    map.set(vertex2, pos1);
    heap[pos1] = heap[pos2];
    heap[pos2] = tmp;
  }
  //Arrange heap from child to it's parent
  function fix(pos) {
    //If it's not the root
    if (pos) {
      const parent = (pos - 1) >> 1;
      if (heap[pos].data < heap[parent].data) {
        swap(pos, parent);
        fix(parent);
      }
    }
  }
  //arrange heap from parent to it's children
  function arrangeHeap(parent) {
    const left = parent * 2 + 1;
    const right = left + 1;
    //Stop when that node has less than 2 children
    //None child
    if (heap[left] === undefined && heap[right] === undefined) return;
    //One child
    if (heap[left] === undefined || heap[right] === undefined) {
      if (heap[left] === undefined) {
        heap[right].data < heap[parent].data && swap(right, parent);
      } else heap[left].data < heap[parent].data && swap(left, parent);
      return;
    }
    //Continue sorting heap
    if (heap[parent].data > Math.min(heap[left].data, heap[right].data)) {
      if (heap[left].data < heap[right].data) {
        swap(left, parent);
        arrangeHeap(left);
      } else {
        swap(right, parent);
        arrangeHeap(right);
      }
    }
  }
  this.getHeap = function () {
    return heap;
  };
  this.getMap = function () {
    return map;
  };
  this.getSize = function () {
    return heap.length;
  };
  this.get = function (vertex) {
    return heap[map.get(vertex)];
  };
  this.has = function (vertex) {
    return map.has(vertex);
  };
  this.add = function (vertex, data) {
    const pos = heap.length;
    const node = new Node(vertex, data);
    //Add node to the heap, add position of the vertex to map
    heap.push(node);
    map.set(vertex, pos);
    //Fix the heap(From child to parent in case current data is smaller than parent)
    fix(pos);
    return node;
  };
  this.min = function () {
    return heap[0];
  };
  //Remove a node at position `pos` in the heap
  this.removeAt = function (pos) {
    //Do nothing is the position is invalid
    if (pos >= heap.length) return null;
    let node = heap[pos];
    //swap the current position with the last position
    swap(pos, heap.length - 1);
    //Get rid of the node that we need to remove
    heap.pop();
    //Remove vertex of that node in map
    map.delete(node.vertex);
    arrangeHeap(pos);
    return node;
  };
  //Remove a vertex
  this.removeVertex = function (vertex) {
    return this.removeAt(map.get(vertex));
  };
  //extract the min node in the heap
  this.extractMin = function () {
    return this.removeAt(0);
  };
  //Set value of a vertex to a new value
  this.set = function (vertex, data) {
    const pos = map.get(vertex);
    const node = heap[pos];
    node.data = data;
    //After updating
    //Fix if current is smaller than child(from child to parent)
    fix(pos);
    //Arrange if current is bigger than child(from parent to child)
    arrangeHeap(pos);
    return node;
  };
}

//******************** KRUSKAL's ALGORITHM ****************
///////////////////////// 2nd solution //////////////////////////
///////////////////////// 2nd solution //////////////////////////
///////////////////////// 2nd solution //////////////////////////
///////////////////////// 2nd solution //////////////////////////
///////////////////////// 2nd solution //////////////////////////
///////////////////////// 2nd solution //////////////////////////
///////////////////////// 2nd solution //////////////////////////
///////////////////////// 2nd solution //////////////////////////
///////////////////////// 2nd solution //////////////////////////
///////////////////////// 2nd solution //////////////////////////
///////////////////////// 2nd solution //////////////////////////
///////////////////////// 2nd solution //////////////////////////
///////////////////////// 2nd solution //////////////////////////
///////////////////////// 2nd solution //////////////////////////
function solution(n, wires) {
  let map = new Map();
  function makeSet(data) {
    let node = {};
    node.rank = 0;
    node.data = data;
    node.parent = null;
    map.set(data, node);
  }
  function findSet(node) {
    if (!node.parent) return node;
    return (node.parent = findSet(node.parent));
  }
  function findRepresentSet(data) {
    return findSet(map.get(data)).data;
  }
  function unionSet(data1, data2) {
    let node1 = map.get(data1),
      node2 = map.get(data2),
      parent1 = findSet(node1),
      parent2 = findSet(node2),
      rank1 = parent1.rank,
      rank2 = parent2.rank;
    if (parent1.data === parent2.data) return;
    if (rank1 >= rank2) {
      parent1.rank = rank1 === rank2 ? rank1 + 1 : rank1;
      parent2.parent = parent1;
    } else parent1.parent = parent2;
  }

  let result = 0;
  for (let i = 0; i < n; i++) makeSet(i);
  wires
    .sort((a, b) => a[2] - b[2])
    .map(([vertex1, vertex2, length]) => {
      const parent1 = findRepresentSet(vertex1),
        parent2 = findRepresentSet(vertex2);
      if (parent1 !== parent2) {
        result += length;
        unionSet(vertex1, vertex2);
      }
    });
  return result;
}

//******************** PRIM's ALGORITHM ****************
//******************** Priority Queue (Binary Heap) ****************
////////////////////////// 3rd solution //////////////////////////
////////////////////////// 3rd solution //////////////////////////
////////////////////////// 3rd solution //////////////////////////
////////////////////////// 3rd solution //////////////////////////
////////////////////////// 3rd solution //////////////////////////
////////////////////////// 3rd solution //////////////////////////
////////////////////////// 3rd solution //////////////////////////
////////////////////////// 3rd solution //////////////////////////
////////////////////////// 3rd solution //////////////////////////
////////////////////////// 3rd solution //////////////////////////
////////////////////////// 3rd solution //////////////////////////
////////////////////////// 3rd solution //////////////////////////
////////////////////////// 3rd solution //////////////////////////
////////////////////////// 3rd solution //////////////////////////

// This solution is using Prim's Algorithm. A greedy algorithm that is used
// to find the minimum spanning tree of a graph.

// It starts by initializing an adjacency matrix, where the value of each element is set to Infinity except for
// the diagonal elements, which are set to 0.

// It then iterates through the edges of the graph and sets the corresponding elements of the adjacency matrix
// to the weight of the edge, for both directions.

// It then creates a copy of the adjacency matrix and a Set to keep track of the discovered vertices. It also
// initializes a variable totLen to keep track of the total length of the edges in the minimum spanning tree.

// It then starts a loop that iterates n times and for each iteration, it checks if the current vertex has been
// discovered or not. If it hasn't, it creates a priority queue and adds the current vertex to it with distance 0.

// It then enters a while loop that continues as long as the priority queue is not empty. In each iteration,
// it extracts the minimum element of the priority queue and adds it to the discovered set. It also adds the
// distance of the extracted element to the totLen variable.

// It then iterates through all other vertices and checks if the current vertex can reach the other vertex and
// if the other vertex has been discovered or not. If the other vertex has not been discovered and the distance
// between the current vertex and the other vertex is less than infinity, it adds the other vertex to the priority
// queue or if the vertex is already in the priority queue it decrease the key of the vertex to update the distance.

// The key idea of this solution is that it uses a priority queue to keep track of the vertices that are not yet
// part of the minimum spanning tree and the distance of each vertex to the discovered vertices. It starts by
// adding an arbitrary vertex to the priority queue and then in each iteration, it extracts the vertex with the
// minimum distance to the discovered vertices and adds it to the discovered set. It also updates the distances
// of the other vertices that are not yet in the discovered set. By doing this, the algorithm guarantees that it
// will only add edges that are part of the minimum spanning tree.

// The solution also uses an implementation of a priority queue which is a data structure that allows you to
//  efficiently access the element with the highest or lowest priority. It uses a technique called a binary heap
//  to implement the priority queue which is a complete binary tree that satisfies the heap property, where each
//  node has a priority that is less than or equal to its parent node.

function solution(n, wires) {
  const adjMatrix = new Array(n);

  for (let i = 0; i < n; i += 1) {
    adjMatrix[i] = new Array(n);
  }

  for (i = 0; i < n; i += 1) {
    for (j = 0; j < n; j += 1) {
      adjMatrix[i][j] = i === j ? 0 : Infinity;
    }
  }

  for (const [u, v, w] of wires) {
    adjMatrix[u][v] = w;
    adjMatrix[v][u] = w;
  }

  const adjMatrixCopy = adjMatrix.slice();

  const discoveredVertices = new Set();

  let totLen = 0;

  for (let i = 0; i < n; i += 1) {
    if (!discoveredVertices.has(i)) {
      const pq = new PriorityQueue();
      pq.add(0, i, i);
      while (pq.size() > 0) {
        const [dist, u, v, index] = pq.extractMin();

        discoveredVertices.add(v);
        totLen += dist;

        for (let dest = 0; dest < n; dest += 1) {
          let candidateDistance = adjMatrix[v][dest];
          if (dest !== v && candidateDistance < Infinity && !discoveredVertices.has(dest)) {
            if (!pq.has(dest)) {
              pq.add(candidateDistance, v, dest);
            } else {
              if (pq.getDistance(dest) > candidateDistance) {
                pq.decreaseKey(dest, candidateDistance);
              }
            }
          }
        }
      }
    }
  }

  return totLen;
}

function PriorityQueue(arg) {
  this._heap = [];
  this._hashMap = {};
}

PriorityQueue.prototype.size = function () {
  return this._heap.length;
};

PriorityQueue.prototype.add = function (dist, u, v) {
  let node = [dist, u, v, this.size()]; // last entry is index in heap
  this._heap.push(node);
  this._hashMap[v] = node;

  let currentIndex = this.size() - 1;
  let parentIndex = Math.ceil(currentIndex / 2) - 1;
  while (currentIndex > 0 && node[0] < this._heap[parentIndex][0]) {
    const nodeCopy = node.slice();
    const parentNodeCopy = this._heap[parentIndex].slice();

    nodeCopy[3] = parentIndex;
    parentNodeCopy[3] = currentIndex;

    this._heap[parentIndex] = nodeCopy;
    this._hashMap[nodeCopy[2]] = nodeCopy;
    this._heap[currentIndex] = parentNodeCopy;
    this._hashMap[parentNodeCopy[2]] = parentNodeCopy;

    currentIndex = parentIndex;
    parentIndex = Math.ceil(currentIndex / 2) - 1;
  }
};

PriorityQueue.prototype.extractMin = function () {
  if (this._heap.length === 0) return null;

  const nodeCopy = this._heap[0];
  const endCopy = this._heap[this._heap.length - 1];

  nodeCopy[3] = this.size() - 1;
  endCopy[3] = 0;

  this._heap[0] = endCopy;
  this._heap[this._heap.length - 1] = nodeCopy;

  this._hashMap[endCopy[2]] = endCopy;
  delete this._hashMap[nodeCopy[2]];

  const temp = this._heap.pop();
  if (this._heap.length === 0) return temp;

  let currentIndex = 0;
  let leftChildIndex = 2 * currentIndex + 1;
  let rightChildIndex = 2 * currentIndex + 2;

  let curr = this._heap[currentIndex];
  let min = this._heap[currentIndex];
  let minIndex = currentIndex;

  while (this._heap[leftChildIndex] || this._heap[rightChildIndex]) {
    if (this._heap[leftChildIndex] && this._heap[leftChildIndex][0] < min[0]) {
      min = this._heap[leftChildIndex];
      minIndex = leftChildIndex;
    }

    if (this._heap[rightChildIndex] && this._heap[rightChildIndex][0] < min[0]) {
      min = this._heap[rightChildIndex];
      minIndex = rightChildIndex;
    }

    if (curr === min) {
      break;
    } else {
      const tempCurr = curr.slice();
      const tempMin = min.slice();

      tempCurr[3] = minIndex;
      tempMin[3] = currentIndex;

      this._heap[currentIndex] = tempMin;
      this._hashMap[tempMin[2]] = tempMin;
      this._heap[minIndex] = tempCurr;
      this._hashMap[tempCurr[2]] = tempCurr;

      currentIndex = minIndex;
      leftChildIndex = 2 * currentIndex + 1;
      rightChildIndex = 2 * currentIndex + 2;

      curr = this._heap[currentIndex];
      min = this._heap[currentIndex];
    }
  }

  return temp;
};

PriorityQueue.prototype.decreaseKey = function (u, dist) {
  let currNode = this._hashMap[u];
  currNode[0] = dist;

  let currIndex = currNode[3];
  let parentIndex = Math.ceil(currIndex / 2) - 1;

  while (currIndex > 0 && currNode[0] < this._heap[parentIndex][0]) {
    const nodeCopy = currNode.slice();
    const parentNodeCopy = this._heap[parentIndex].slice();
    nodeCopy[3] = parentIndex;
    parentNodeCopy[3] = currIndex;

    this._heap[parentIndex] = nodeCopy;
    this._hashMap[nodeCopy[2]] = nodeCopy;
    this._heap[currIndex] = parentNodeCopy;
    this._hashMap[parentNodeCopy[2]] = parentNodeCopy;

    currIndex = parentIndex;
    parentIndex = Math.ceil(currIndex / 2) - 1;
  }
};

PriorityQueue.prototype.getDistance = function (u) {
  return this._hashMap[u][0];
};

PriorityQueue.prototype.has = function (u) {
  return this._hashMap[u];
};
