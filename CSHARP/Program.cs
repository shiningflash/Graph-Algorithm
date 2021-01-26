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

        // PrimsMST pmst = new PrimsMST();
        // pmst.managePrimsMST(lines);

        // KruskalMST kmst = new KruskalMST();
        // kmst.manageKruskalMST(lines);

        SCC scc = new SCC();
        scc.manageSCC(lines);

    }
}
