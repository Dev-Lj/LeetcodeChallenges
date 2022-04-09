#include <stdio.h>

int get_next_idx(int idx, int other) {
    int next = (idx + 1) % 4;
    if (next == other || next == idx) {
        next = (next + 1) % 4;
    }
    return next;
}

void resolve_testcase(int *testcase) {
    /*
    Step 1:
        a + b = x1
        a - b = x2
      + ___________
        2a = x1 + x2

        a + b = x1
        a - b = x2
      - ___________
        2b = x1 - x2
    */
    
    // {possible a or b, index x1, index x2}
    int p_a[6][3];
    int p_b[6][3];
    int pos_a = 0;
    int pos_b = 0;
    for (int i = 0; i < 4; i++)
    {

        for (int j = i+1; j < 4; j++) {
            
            int a = (testcase[i] + testcase[j])/2;
            int b = (abs(testcase[i] - testcase[j]))/2;

            // Ensure a and b is in bounds
            if (a <=0 || a > 1e4 || b <=0 || b > 1e4)
            {
                continue;
            }

            int pos_others = 0;
            int others[2];
            for (int x = 0; x < 4; x++)
            {
                if (x == i || x == j)
                {
                    continue;
                }
                others[pos_others] = testcase[x];
                pos_others++;               
            }
            if ((a*b == others[0] && a/b == others[1]) || (a*b == others[1] && a/b == others[0])) {
                printf("%d %d\n", a, b);
                return;
            }
        }

    }
    printf("-1 -1\n");
}

int main(void) {
	int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++) {
        int testcase[4];
        scanf("%d", &testcase[0]);
        scanf("%d", &testcase[1]);
        scanf("%d", &testcase[2]);
        scanf("%d", &testcase[3]);
        resolve_testcase(testcase);
    }
	return 0;
}

