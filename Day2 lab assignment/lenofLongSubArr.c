// 4. WAP to length of the longest Sub-Array with the sum of the elements equal to the
// given value k.

#include <stdio.h>
int main()
{
    int n;
    int max_len = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n], k = 0;
    printf("\nEntering array..\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the sum of sub array (k) =  ");
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j <= n - 1; j++)
        {
            sum = sum + arr[j];
            if (sum == k)
            {
                int current_len = j - i + 1;
                if (current_len > max_len)
                {
                    max_len = current_len;
                }
            }
        }
    }
    printf("\nLength of the longest Sub-Array with the sum of the elements equal to the %d is %d\n", k, max_len);
}
