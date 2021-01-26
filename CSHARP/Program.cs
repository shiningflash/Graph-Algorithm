using System;

public class Program {
    public static void Main(string[] args) {
        string[] lines = System.IO.File.ReadAllLines("in.txt");

        // BFS bfs = new BFS();
        // bfs.manageBFS(lines);

        // DFS dfs = new DFS();
        // dfs.manageDFS(lines);

        // TopSort ts = new TopSort();
        // ts.manageTopSort(lines);

        // Dijkstra dijkstra = new Dijkstra();
        // dijkstra.manageDijkstra(lines);

        PrimsShortestPath psp = new PrimsShortestPath();
        psp.managePrimsShortestPath(lines);
    }
}
