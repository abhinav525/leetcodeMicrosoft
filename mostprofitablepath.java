//2467. Most Profitable Path in a Tree
class Solution {
    Map<Integer,List<Integer>> tree =new HashMap<>();
    int[] parent=null;
    int[] dist=null;
    private void constructtree(int [][] edges)
    {
        int n = edges.length;
        for(int i=0;i<n;i++)
        {
            int n1 = edges[i][0];
            int n2=edges[i][1];
            if(!tree.containsKey(n1))
            {
                tree.put(n1,new ArrayList<>());
            }
            if(!tree.containsKey(n2))
            {
                tree.put(n2,new ArrayList<>());
            }
            tree.get(n1).add(n2);
            tree.get(n2).add(n1);
        }
    }
    //parent
    void dfstofindpar(int curr,int currpar,int currdist){
        dist[curr]=currdist;
        parent[curr]=currpar;
        for(Integer currNeighbour: tree.get(curr)){
            if(currNeighbour==currpar){//edge case
                continue;
            }
            dfstofindpar(currNeighbour,curr,currdist+1);
        }
    }
    Set<Integer> visited = new HashSet<>();
    int ans =0;
    int maxans=Integer.MIN_VALUE;

    private void dfs(int curr,int[] amount){
        visited.add(curr);

        ans+=amount[curr];
        int trav=0;
        for(Integer currNeighbour:tree.get(curr)){
            if(visited.contains(currNeighbour)){

                continue;

            }
            trav++;
            dfs(currNeighbour,amount);
        }
        if(trav==0){
            maxans=Math.max(ans,maxans);
        }
        ans-=amount[curr];//backtracking to parent to decrease amount
    }

    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        constructtree(edges);
        int n=edges.length;
        parent = new int[n+1];
        dist=new int[n+1];
        Arrays.fill(parent,-1);
        Arrays.fill(dist,-1);
        dfstofindpar(0,0,0);
        int curr=bob;
        int currdist=0;
        while(curr!=0){
            if(dist[curr]>currdist){
                amount[curr]=0;

            }else if(dist[curr] == currdist){
                amount[curr]/=2;

            }
            curr=parent[curr];
            currdist++;

        }
        dfs(0,amount);
        return maxans;


    }
}
