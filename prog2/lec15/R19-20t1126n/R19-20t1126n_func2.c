//課題19 自作関数の実体のうち、“R19-xxxx_func1.c”で記述されていない関数が記述されたもの
//20t1126n YANG GUANGZE

#include "myhead\R19-20t1126n.h"

void load_data(Eng *start)
{
    FILE    *fp;
    char    fname[20];
    Eng	*node, *ip, wk;

	printf("Input file name:");	scanf("%s",fname);

	fp=fopen(fname,"r");
	if(fp==NULL){
		printf("Can't open %s!\n",fname);
		exit(1);
	}

	while(fscanf(fp,"%d %s %c %d %lf", &wk.ID, wk.name, &wk.data.gender, &wk.data.age, &wk.data.weight)!=EOF){
			
			node=Alloc_Node();
			*node=wk;

			for(ip=start;ip->next!=NULL;ip=ip->next){
				if( node->ID < ip->next->ID){ 
					node->next=ip->next;
					ip->next=node;
					break;
				}
			}
			
			if(ip->next==NULL){
				ip->next=node;
				node->next=NULL;
			}
	}
	fclose(fp);	//ファイルのクローズ
}

double bmr(Eng *obj){
    double B=0.0;

    if(obj->data.gender == 'M' ){   //男性の場合
        if( obj->data.age >= 15 && obj->data.age <= 17){
            B = 27.0*obj->data.weight;
        }else if( obj->data.age >= 18 && obj->data.age <= 29){
            B = 24.0*obj->data.weight;
        }else if( obj->data.age >= 30 && obj->data.age <= 49){
            B = 22.3*obj->data.weight;
        }else if( obj->data.age >= 50 && obj->data.age <= 69){
            B = 21.5*obj->data.weight;
        }else{
            B = 0.0;
        }
    }
    if( obj->data.gender =='F'){    //女性の場合
       if( obj->data.age >= 15 && obj->data.age <= 17){
            B = 25.3 * (obj->data.weight);
        }else if(obj->data.age >= 18 && obj->data.age <= 29){
            B = 23.6*obj->data.weight;
        }else if(obj->data.age >= 30 && obj->data.age <= 49){
            B = 21.7*obj->data.weight;
        }else if(obj->data.age >= 50 && obj->data.age <= 69){
            B = 20.7*obj->data.weight;
        }else{
            B = 0.0;
        }
    }
    return B;
}

void print_list(Eng *start){
    Eng *ip;

	for(ip=start->next; ip!=NULL; ip=ip->next){
		printf("%-8d%-8s%10c%10d%10.1lf\n",
			ip->ID,ip->name, ip->data.gender, ip->data.age, ip->data.weight);
	}
}

void print_Search_up_down(Eng *start){
    Eng *ip, *jp;
    double min;
    int A, B;
    int i, j, k, N;

    do{
		printf("基礎代謝量(x):"); scanf("%d", &A);
	}while(A == EOF);

    do{
		printf("降順(入力：1) 昇順(入力：2)　:"); scanf("%d", &B);
	}while(B == EOF);

    i=0;
    for(ip=start->next; ip!=NULL; ip=ip->next){
        i++;
	}
    N=i;    //データの総数
    Eng *a[N]; //ポインタ配列

    i=0;
    for(ip=start->next; ip!=NULL; ip=ip->next){
        a[i]=ip;
        i++;
	}

    for(i=0; i<N-1; i++){
        min = bmr(a[i]);
        k=i;
        for(j=i+1; j<N; j++){
            if( bmr(a[j]) > min){
                min = bmr(a[j]);
                k=j;
            }
        }
        jp=a[i]; a[i]=a[k]; a[k]=jp;
    }   //直接選択法

    if(B==1){       //降順
        for(i=0; i<N; i++){
            if(bmr(a[i]) >= A){
                print_node(a[i]);
            }
        }
    }else if(B==2){ //昇順
        for(i=N-1; i>=0; i--){
            if(bmr(a[i]) >= A){
                print_node(a[i]);
            }
        }
    }else{
        printf("エラー\n");
    }
}

Eng *Alloc_Node(void){
	Eng *pt;

	pt=(Eng *)calloc(1, sizeof(Eng));	
	if(pt==NULL){
		printf("記憶領域の確保に失敗しました\n");
		exit(1);
	}

	return pt;
}

void print_node(Eng *ip){
	printf("%-8d%-8s%10c%10d%10.1lf%10.1lf\n",
			ip->ID,ip->name, ip->data.gender, ip->data.age, ip->data.weight, bmr(ip) );
}
