import java.util.HashMap;

/**
 * LongestSubstring
 */
class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> idx = new HashMap<Character, Integer>();
        for (char c : s.toCharArray()) {
            if(!idx.containsKey(c)) {
                idx.put(c, -1);
            }
        }
        int l = 0;
        int r = 0;
        int len = 0;
        while (r < s.length()) {
            while (r<s.length() && idx.get(s.charAt(r))< l) {
                idx.put(s.charAt(r), r);
                r++;
            }
            if((r-l) > len) {
                len = r-l;
            }
            if (r < s.length()) {
                l = idx.get(s.charAt(r)) + 1;
            }
        }
        return len;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int len = sol.lengthOfLongestSubstring("dvdf");
        System.out.println("Result: "+ len);
    }
}