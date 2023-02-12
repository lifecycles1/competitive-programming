function solution(roadRegister) {
  //Store removed nodes
  let removed = new Set();
  const n = roadRegister.length;
  for (let i = 0; i < n; i += 2) {
    if (roadRegister[i][i + 1]) {
      removed.add(i + 1);
      for (let j = 0; j < n; j++) {
        //Merge node i with node i + 1
        //for a node j connected with node i + 1
        //after merging, node i is connected to node j
        //and node j is connect to node i
        roadRegister[i][j] = roadRegister[i][j] || roadRegister[i + 1][j];
        roadRegister[j][i] = roadRegister[i][j];
      }
    }
  }
  //Filter unremoved nodes in graph
  //node[i][i] always equal to false
  return roadRegister
    .filter((v, i) => !removed.has(i))
    .map((v, i) => {
      v = v.filter((o, j) => !removed.has(j));
      v[i] = false;
      return v;
    });
}

// Python solution

// def solution(roadRegister):
//     i = 0
//     while i < len(roadRegister) - 1:
//         if roadRegister[i][i+1]:
//             mergeCity(i, roadRegister)
//             i += 1
//         else:
//             i += 2
//     return roadRegister

// def mergeCity(i, roadRegister):
//     for j in range(len(roadRegister)):
//         if i != j:
//             roadRegister[i][j] = roadRegister[j][i] = roadRegister[j][i] or roadRegister[j][i+1]

//     for j in range(len(roadRegister)):
//         del roadRegister[j][i+1]
//     del roadRegister[i+1]
