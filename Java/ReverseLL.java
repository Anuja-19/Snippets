public class ReverseLL {
     private int size;
     private Node head;
     private Node tail;

     private class Node {
           int data;
           Node next;
        }
        //O(1)
        public void addLast(int item){

        //create new Node
        Node nn =new Node();
        nn.data=item;
        nn.next=null;

        // attach with previous node
            if(size>=1){
                this.tail.next=nn;
            }


              // update summary Object
            if(this.size==0){
          this.head=nn;
          this.tail=nn;
          this.size++;
          }
          else{
          this.tail=nn;
          this.size++;
           }

         }

         public int size(){
         return this.size;
         }

     //O(1)
     public void addFirst(int item){


       // Create a new Node
        Node nn=new Node();
        nn.data=item;
        nn.next=null;

        //attach with old linkedList
        if(size>=1){
            nn.next=this.head;
        }

        //updating summary Object
        if(this.size==0){
            this.head=nn;
            this.tail=nn;
            this.size++;
        }
        else{
           this.head=nn;
           this.size++;
        }
     }

     //O(1)
     public int getFirst() throws Exception{
         if(this.size==0){
             throw new Exception("List is Empty");
         }
       return this.head.data;
        }

     //O(1)
     public int getLast(){

       return this.tail.data;
        }

     //O(n)
     public int getAt(int index) throws Exception {
            if(this.size==0){
                throw new Exception("LinkedList is Empty");
            }
            if(index<0||index>=this.size){
                throw new Exception("Invalid Index");
            }
            Node temp=this.head;
            for (int i = 1; i <=index ; i++) {
                temp = temp.next;
            }
            return temp.data;
        }

     //O(n)
     private Node getNode(int index) throws Exception {
            if(this.size==0){
                throw new Exception("LinkedList is Empty");
            }
            if(index<0||index>=this.size){
                throw new Exception("Invalid Index");
            }
            Node temp=this.head;
            for (int i = 1; i <=index ; i++) {
                temp = temp.next;
            }
            return temp;
        }

     //O(n)
        public void addAt(int item,int index) throws Exception {
           if(index<0||index>this.size){
               throw new Exception("Invalid Index");
           }
           if(index==0){
               addFirst(item);
           }
           else if(index==this.size){
               addLast(item);
           }else {
               Node nn = new Node();
               nn.data = item;
               nn.next = null;
               Node prevNode = getNode(index - 1);
//             Node atCurrIndex = getNode(index);  // or we can also write here
               Node atCurrIndex=prevNode.next;   // both are same thing
               prevNode.next = nn;
               nn.next =atCurrIndex;
               this.size++;
           }
        }

        public int  RemoveFirst() throws Exception {
            if (this.size == 0) {
                throw new Exception("LinkedList is Empty");

            }
            int val=this.head.data;

            if (this.size == 1) {
                this.head = null;
                this.tail = null;
                this.size--;
            } else {
                this.head = this.head.next;
                this.size--;
            }
            return val;
        }

        //O(n)
        public int RemoveLast() throws Exception {
            if (this.size == 0) {
                throw new Exception("LinkedList is Empty");

            }
            int val=this.tail.data;
            if (this.size == 1) {
                this.head = null;
                this.tail = null;
                this.size--;
            } else {
                Node prevNode = getNode(this.size - 2);
                this.tail = prevNode;
                this.tail.next=null;
                this.size--;
            }
     return val;
     }

//     O(n)
        public int RemoveAt(int index) throws Exception {
          if(this.size==0){
              throw new Exception("LinkedList is Empty");
          }
          if(index<0||index>=this.size){
              throw new Exception("Invalid INdex");
          }

          if(index==0){
            int val=  RemoveFirst();
            return val;
          }
          else if(index==this.size-1){
              int val=RemoveLast();
              return val;
          }
          else{
              int val=this.getAt(index);
              Node preNode=getNode(index-1);
              Node nexNode=getNode(index+1);
              preNode.next=nexNode;
              this.size--;
             return  val;
          }
        }
      //O(n)
        public void ReverseData() throws Exception {
         if(this.size==0){
             throw new Exception("linkedList is Empty");
         }
         int left=0;
         int right=this.size-1;

         while(left<right){
          Node LN=getNode(left);
          Node Rn=getNode(right);
          int temp=LN.data;
          LN.data= Rn.data;
          Rn.data=temp;
          left++;
          right--;
         }
        }


        public void ReversePointer() throws Exception {
         if(this.size==0){
             throw new Exception ("Linked List is Empty");
         }
         else if (this.size==2||this.size==1) {
             Node temp = this.head;
             this.head = this.tail;
             this.tail = temp;
         }
         else{
          Node prevNode=this.head;
          Node currNode=this.head.next;


          while(currNode!=null){
              Node aheadNode=currNode.next;
              currNode.next=prevNode;
              prevNode=currNode;
              currNode=aheadNode;

          }
             Node temp = this.head;
             this.head = this.tail;
             this.tail = temp;
             this.tail.next=null;
            }


        }

        public int midNode(){
         Node midNode=this.head;
         Node aheadNOde=midNode.next.next;
         while(aheadNOde!=null){
             System.out.println(midNode.data);
             midNode=midNode.next;
             aheadNOde=aheadNOde.next.next;
         }
         return midNode.data;
        }

        //O(n)
      public void display(){
        Node temp=this.head;
        while(temp!=null){
            System.out.print(temp.data+" -> ");
            temp=temp.next;
        }
         System.out.println("End");
     }

     public static void main(String[] args) throws Exception {
         ReverseLL list=new ReverseLL();
         list.addFirst(10);
         list.addFirst(20);
         list.addFirst(30);
         list.addFirst(40);
         list.addFirst(70);
         list.display();
         list.ReverseData();
         list.display();
     }

 }