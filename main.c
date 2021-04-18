#include <stdio.h>
#include <stdlib.h>

#define stack_size 10 //yığın boyutu makrosu

struct linkedlist
{
	int num;
	struct linkedlist* next;
};

struct stack
{
	struct linkedlist* data[stack_size];
	int top;
};


void push(struct stack* stk, struct linkedlist *list)//yığına liste ekleme
{
	if (stk->top == stack_size - 1)//doluluk kontrolü
	{
		printf("Hata...\nYığın Dolu...");
	}
	else
	{
		stk->top++;
		stk->data[stk->top] = list;
	}
}

void reset(struct stack* stk)//yığını sıfırlama
{
	stk->top = -1;
}

int pop(struct stack* stk)//yığına son giren elemanı çıkarma
{
	if (stk->top == -1)//yığının doluluk durumu kontrolü
	{
		printf("Hata...\nYığın Zaten Boş...");
		return -1;
	}
	else
	{
		stk->top--;
		return stk->top;
	}
}

struct linkedlist* createlist(char studentnum[10])//liste oluşturma
{
	struct linkedlist* list = (struct linkedlist*)malloc(sizeof(struct linkedlist));//dinamik bellek ayırımı
	char uchane[3] = { studentnum[0], studentnum[1], studentnum[2] };
	int uchanesayı;
	int uchane1, uchane2, uchane3;
	//ilk üç haneyi int'e çevirme işlemi
	//ASCII değerlerini int değerlerine çevirmek için '0' sayısının ASCII değerini çıkarıldı
	uchane1 = (int)uchane[0] - 48;
	uchane2 = (int)uchane[1] - 48;
	uchane3 = (int)uchane[2] - 48;
	uchanesayı = uchane1 * 100 + uchane2 * 10 + uchane3;

	list->num = uchanesayı;
	//dinamik bellek ayırımı
	struct linkedlist* list1 = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	struct linkedlist* list2 = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	struct linkedlist* list3 = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	struct linkedlist* list4 = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	struct linkedlist* list5 = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	struct linkedlist* list6 = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	struct linkedlist* list7 = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	struct linkedlist* list8 = (struct linkedlist*)malloc(sizeof(struct linkedlist));
	struct linkedlist* list9 = (struct linkedlist*)malloc(sizeof(struct linkedlist));

	//düğüm bağlama

	list->next = list1;
	list1->next = list2;
	list2->next = list3;
	list3->next = list4;
	list4->next = list5;
	list5->next = list6;
	list6->next = list7;
	list7->next = list8;
	list8->next = list9;
	list9->next = NULL;

	//ASCII değerlerini int değerlerine çevirmek için '0' sayısının ASCII değeri çıkarıldı

	list1->num = (int)studentnum[0] - 48;
	list2->num = (int)studentnum[1] - 48;
	list3->num = (int)studentnum[2] - 48;
	list4->num = (int)studentnum[3] - 48;
	list5->num = (int)studentnum[4] - 48;
	list6->num = (int)studentnum[5] - 48;
	list7->num = (int)studentnum[6] - 48;
	list8->num = (int)studentnum[7] - 48;
	list9->num = (int)studentnum[8] - 48;

	return list;
}

void printlist(struct stack* stk)//stack içindeki listeleri yazdırır
{
	for (int i = 0; i <= stk->top; i++)//liste seçimi
	{
		struct linkedlist* l = stk->data[i];
		printf("\n%d. numara: ", i+1);
		struct linkedlist* newl = l->next;
		while (1)//liste yazdırma
		{
			printf("%d", newl->num);
			if (newl->next == NULL) break;
			newl = newl->next;
		}
	}
}

void smallestlist(struct stack* stk)//yığın içindeki elemanları son uç hanesine göre karşılaştırıp en küçüğü bastırır
{//son üç rakamı bulma
	int top = stk->top;
	int min = stk->data[0]->next->next->next->next->next->next->next->num * 100 + stk->data[0]->next->next->next->next->next->next->next->next->num * 10 + stk->data[0]->next->next->next->next->next->next->next->next->next->num;
	int a;
	int last3;
	for (int i = 0; i <= top; i++) //en küçük listenin bulunması
	{
		last3 = stk->data[i]->next->next->next->next->next->next->next->num * 100 + stk->data[i]->next->next->next->next->next->next->next->next->num * 10 + stk->data[i]->next->next->next->next->next->next->next->next->next->num;
		if (last3 < min)
		{
			min = stk->data[i]->next->next->next->next->next->next->next->num * 100 + stk->data[i]->next->next->next->next->next->next->next->next->num * 10 + stk->data[i]->next->next->next->next->next->next->next->next->next->num;
			a = i;
		}
	}
	struct linkedlist* newl = stk->data[a]->next;
	while (1)//en küçük listenin yazdırılması
	{
		printf("%d", newl->num);
		if (newl->next == NULL) break;
		newl = newl->next;
	}

}

int main()
{
	int inp;//girdi değişkeni
	struct stack* stk = (struct stack*)malloc(sizeof(struct stack));//yığın için dinamik bellek ayırımı
	stk->top = -1;
	while (1)
	{
		printf("\nYeni numara eklemek icin '1'e, numaralari yazdirmak icin '2'ye, en kucuk numarayi goruntulemek icin '3'e basin...\nCikis yapmak icin '0'a basin...\n");
		scanf("%d", &inp);
		if (inp == 0) break;//çıkış yapma komutu
		else if (inp == 1)//oğrenci numarası girme
		{
			printf("Lutfen ogrenci numarasini girin\n");
			char stdn[10];
			scanf("%s", &stdn);
			struct linkedlist* l = createlist(stdn);
			push(stk, l);
		}
		else if (inp == 2)//liste bastırma
		{
			printlist(stk);
		}
		else if (inp == 3)//en küçük listeyi bastırma
		{
			smallestlist(stk);
		}
	}
	return 0;
}
