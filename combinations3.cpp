// all the number will be positive integers and must not contains duplicate number.This is backtracking technique ,we will initiate from begning and find the remaining sum from the next digits
class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> result=new ArrayList();
        combinations(1,k,n,new LinkedList(),result);
        return result;

    }
    private void combinations(int start,int k,int n,LinkedList ll,List<List<Integer>> result)
    {
        if(k<0||n<0)
         return;
     if(k==0 && n==0){
          result.add(new ArrayList(ll));
          return;
     }
     for(int i=start;i<=9;i++)
     {
         ll.add(i);
         combinations(i+1,k-1,n-i,ll,result);//here if a num is taken and added then it will be removed from a sum k and next num will be taken i+1 and number will be decreased from the main array.
         ll.removeLast();//backtrack;
     }

    }

}
