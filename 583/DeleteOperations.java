class Solution {
    public int get_diagonal(int[][] m, int i, int j) {
        return  (j-1 < 0 || i-1 < 0) ? 0 : m[i-1][j-1];
    }

    public int getMax(int[][] m, int i, int j) {
        int l = (j-1 < 0) ? 0 : m[i][j-1];
        int d = (j-1 < 0 || i-1 < 0) ? 0 : m[i-1][j-1];
        int u = (i-1 < 0) ? 0 : m[i-1][j];

        return Math.max(Math.max(l, d), u);
    }

    public int minDistance(String word1, String word2) {
        int[][] m = new int[word1.length()][word2.length()];

        for (int i = 0; i < word1.length(); i++) {
            for (int j = 0; j < word2.length(); j++) {
                m[i][j] = 0;
            }
        }

        for (int i = 0; i < word1.length(); i++) {
            for (int j = 0; j < word2.length(); j++) {
                if (word1.charAt(i) == word2.charAt(j)) {
                    m[i][j] = this.get_diagonal(m, i, j) + 1;
                } else {
                    m[i][j] = this.getMax(m, i, j);
                }
            }
        }
        int len_s = m[word1.length()-1][word2.length()-1];

        return (word1.length()-len_s) + (word2.length() - len_s);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println("Result: " + sol.minDistance("food", "money"));
    }
}
