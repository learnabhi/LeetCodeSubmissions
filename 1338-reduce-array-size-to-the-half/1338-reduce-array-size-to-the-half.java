class Solution {
    public int minSetSize(int[] arr) {
       List<Integer> list = Arrays.stream(arr).boxed().collect(Collectors.toList());
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        for (Integer integer : list) {
            freqMap.put(integer, freqMap.getOrDefault(integer, 0) + 1);
        }

        list = list.stream().sorted(Comparator.comparing(freqMap::get).reversed()).collect(Collectors.toList());

        int removed = 0 , half= list.size() / 2;
        int ans = 0;
        while(removed < half){
            ans++;
            removed += freqMap.get(list.get(removed));
        }

        return ans;
    }
}