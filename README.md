# 1D partitioned parallel BFS on large graphs

### Compilation Instructions
`mpicc serial_and_parallel_bfs.c`

### Running Instructions on Stampede supercomputer
`ibrun -np num_of_processors a.out num_of_vertices_per_processor source_vertex`

### Expected output
##### Sample output for ibrun -np 4 a.out 100 0
```
Total vertices in the graph : 40000
Serial BFS complete. Time taken = 0.023453
Parallel BFS complete. Time taken = 0.001668
```
