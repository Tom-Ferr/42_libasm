#include "libasm_bonus.h"
#include "string.h"

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

        int len = 7;
        while(len){
                int* data2 = (int*)malloc(sizeof(int));     
                if(len % 2){
                    *data2 = rand() % 100;
                    ft_list_push_front(&lst, data2);
                }
                else {
                    *data2 = 42;
                    ft_list_push_front(&lst, data2);

                }
            --len;
        }
        

       t_list* plst = lst;
        while(plst){
            printf("%d, ",  *((int*)plst->data));
            plst = plst->next;
        };


        printf("\nList_Size\n");

        int size = ft_list_size(lst);
        printf("%d\n", size);


        printf("\nList_Remove_If\n");

        ft_list_remove_if(&lst, data, ft_strcmp, free);

        size = ft_list_size(lst);
        plst = lst;
        while(plst){
            printf("%d, ",  *((int*)plst->data));
            plst = plst->next;
        };
        printf("\nlst size: %d\n", size);
        plst = lst;
        while(plst){
            free(plst->data);
            t_list* del = plst;
            plst = plst->next;
            free(del);
        }
    }

     printf("\nList_Sort\n");
    {
        //create list
        char* data = (char*)malloc(sizeof(char));
        *data = 42;
        t_list* lst = ft_create_elem(data);

        int len = 7;
        while(len--){
            data = (char*)malloc(sizeof(char));
                *data = rand() % 255;
             ft_list_push_front(&lst, data);
        }

        //print list
        t_list* plst = lst;
        while(plst){
            printf("%d, ",  *((char*)plst->data));
            plst = plst->next;
        }
        printf("\n");

        //sort
        ft_list_sort(&lst, ft_strcmp);

        //print sorted list
        plst = lst;
        while(plst){
            printf("%d, ",  *((char*)plst->data));
            plst = plst->next;
        }
        printf("\n");

        //free list
        plst = lst;
        while(plst){
            free(plst->data);
            t_list* del = plst;
            plst = plst->next;
            free(del);
        }

        

    }


	return 0;
}

