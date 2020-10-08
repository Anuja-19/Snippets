import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;


//Kruskal's algorithm to find Minimum spanning tree with Union-Find
public class Kruskal {
	 public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
		 System.out.println("Enter number of nodes");
		 int numNodes = sc.nextInt();
		 System.out.println("Enter number of edges");
		 int edges = sc.nextInt();
		 int[][] edges_weight = new int[edges][3];
		 int temp_edges= edges;
		 int i=0;
		 while(temp_edges>0){
			 System.out.println("Enter node 1 of the edge");
			 edges_weight[i][0]=sc.nextInt();
			 System.out.println("Enter node 2 of the edge");
			 edges_weight[i][1]=sc.nextInt();
			 System.out.println("Enter weight of this edge");
			 edges_weight[i][2]=sc.nextInt();
			 i++;
			 temp_edges--;
		 }
		 solve(numNodes,edges_weight);
	 }
	
    public static int solve(int A, int[][] B) {
        int[]parent=new int[A+1];
        int[]size=new int[A+1];
        
        for(int i=1;i<parent.length;i++){
            parent[i]=i;
            size[i]=1;
        }
        PriorityQueue<int[]>pq = new PriorityQueue<int[]>(B.length, new CustomComparator());
        
        for(int i=0;i<B.length;i++){
            pq.add(B[i]);
        }
        int ans=0;
        while(!pq.isEmpty()){
            int[]arr= pq.poll();
            int a = arr[0];
            int b= arr[1];
            if(find(a,parent)==find(b,parent)){
                continue;
            }
            else{
                union(parent,size,a,b);
                System.out.print(a + "--" + b + "=" + arr[2]);// printing out edges in minimum spanning tree with its weight
                System.out.println();
                
            }
        }
        return ans;
        
    }
    public static void union(int[] parent, int[] size,int A,int B){
        int roota=find(A,parent);
        int rootb= find(B,parent);
        
        if(size[roota]<size[rootb]){
            parent[roota]=rootb;
            size[rootb]+=size[roota];
        }
        else{
            parent[rootb]=roota;
            size[roota]+=size[rootb];
        }
    }
    public static int find(int A,int[]parent){
        while(parent[A]!=A){
            A=parent[A];
        }
        return A;
    } 
    public static class CustomComparator implements Comparator<int[]>{
        public int compare(int[]a,int[]b){
            return a[2]-b[2];
        }
    }
}