#include "libasm_bonus.h"

int main(){

    printf("\nAtoI\n");
    {
        int n;
        n = ft_atoi_base("1010011001", "01");
        printf("%d\n", n);

        n = ft_atoi_base("+ -- +- ++2aZrdaaef", "0123456789abcdef");
        printf("%d\n", n);

        n = ft_atoi_base("1098837239", "0123456789");
        printf("%d\n", n);

        n = ft_atoi_base("1098837239", "01234567890");
        printf("%d\n", n);

        n = ft_atoi_base("1098837239", "0123456 789");
        printf("%d\n", n);

        n = ft_atoi_base("", "0123456789abcdef");
        printf("%d\n", n);

        n = ft_atoi_base("zsbszjbsasn +++----+j bdjdsknlcm..", "0123456789");
        printf("%d\n", n);
    }

     printf("\nList_Push_Front\n");
    {
        int* data = (int*)malloc(sizeof(int));
        *data = 42;
        t_list* lst = ft_create_elem(data);
        int* data2 = (int*)malloc(sizeof(int));
        *data2 = 21;
        ft_list_push_front(&lst, data2);

        printf("%d\n",  *((int*)lst->data));
        printf("%d\n",  *((int*)lst->next->data));


        printf("\nList_Size\n");

        int size = ft_list_size(lst);
        printf("%d\n", size);

        ft_list_remove_if(&lst, data2, ft_strcmp, free);
        size = ft_list_size(lst);
        printf("%d\n", size);
        printf("%d\n",  *((int*)lst->data));
        ft_list_remove_if(&lst, data, ft_strcmp, free);
        size = ft_list_size(lst);
        printf("%d\n", size);
        free(data);
        free(data2);
    }

     printf("\nList_Sort\n");
    {
        int* data = (int*)malloc(sizeof(int));
        *data = 42;
        t_list* lst = ft_create_elem(data);
        int* data2 = (int*)malloc(sizeof(int));
        *data2 = 21;
        ft_list_push_front(&lst, data2);
        int* data3 = (int*)malloc(sizeof(int));
        *data3 = 76;
        ft_list_push_front(&lst, data3);
        int* data4 = (int*)malloc(sizeof(int));
        *data4 = 13;
        ft_list_push_front(&lst, data4);
        int* data5 = (int*)malloc(sizeof(int));
        *data5 = 22;
        ft_list_push_front(&lst, data5);
        int* data6 = (int*)malloc(sizeof(int));
        *data6 = 58;
        ft_list_push_front(&lst, data6);
        int* data7 = (int*)malloc(sizeof(int));
        *data7 = 92;
        ft_list_push_front(&lst, data7);
        int* data8 = (int*)malloc(sizeof(int));
        *data8 = 5;
        ft_list_push_front(&lst, data8);

        t_list* plst = lst;
        while(plst){
            printf("%d, ",  *((int*)plst->data));
            plst = plst->next;
        }
        printf("\n");

        ft_list_sort(&lst, ft_strcmp);

        plst = lst;
        while(plst){
            printf("%d, ",  *((int*)plst->data));
            plst = plst->next;
        }
        printf("\n");

        free(data);
        free(data2);
        free(data3);
        free(data4);
        free(data5);
        free(data6);
        free(data7);
        free(data8);

        plst = lst;
        while(plst){
            t_list* del = plst;
            plst = plst->next;
            free(del);
        }

        

    }


	return 0;
}

