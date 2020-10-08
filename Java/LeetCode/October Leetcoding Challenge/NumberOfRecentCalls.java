class RecentCounter {
    private Queue<Integer> requestTimes;

    public RecentCounter() {
        requestTimes = new LinkedList<>();
    }

    public int ping(int t) {
        requestTimes.add(t);
        while (requestTimes.peek() < t - 3000) {
            requestTimes.remove();
        }
        return requestTimes.size();
    }
}
