#include<stdio.h>
#include<string.h>
#define MAX 10

typedef struct Details{
	char name[15] ;
	int contact_number;
} details;

struct Details person[MAX];

void sort();
int binary_searching(int low, int high, char key[]);

int main(void) {
    char key[15];   
	for (int  i = 0; i < MAX; i++) {
		int temp_contact;
		char temp_name[14];
		printf("Enter the contact number of the persons %d: ",i + 1);
		scanf("%d",&person[i].contact_number);
		printf("Enter the name of the persons %d: ",i + 1);
		scanf("%s",person[i].name);
	}
	sort();
	for (int  i = 0; i < MAX; i++) {
		printf("Name: %s\t", person[i].name);
		printf("Contact number: %d\n", person[i].contact_number);
	}
    printf("Enter the name to search: ");
    scanf("%s", key);
    int index = binary_searching(0, MAX - 1, key);
    if (index == -1) {
        printf("Key was not found!\n");
    } else {
        printf("Key was found at index %d.\n", index);
        printf("Name: %s\n", person[index].name);
        printf("Contact number is %d\n", person[index].contact_number);
    }
	return 0;
}

void sort() {
	int FLAG;
	for (int pass = 0; pass < MAX - 1 ; pass++) {
		FLAG = 0;
		for (int i = 0; i < MAX - pass - 1; i++) {
			int cmp = strcmp(person[i].name, person[i + 1].name);
			if (cmp > 0) {
				details temp;
				strcpy(temp.name, person[i].name);
				strcpy(person[i].name, person[i + 1].name);
				strcpy(person[i + 1].name, temp.name);
				temp.contact_number = person[i].contact_number;
				person[i].contact_number = person[i + 1].contact_number;
				person[i + 1].contact_number = temp.contact_number;
				FLAG = 1;
			}
		}
	}
	if (FLAG == 0) {
		return;
	}
} 

int binary_searching(int low, int high, char key[]) {
    if (low > high) {
        return -1; 
    }
	int mid = (low + high) / 2;
    if (strcmp(person[mid].name, key) == 0) {
        return mid;
    } else if (strcmp(person[mid].name, key) > 0) {
        return binary_searching(low, mid - 1, key);
    } else if (strcmp(person[mid].name, key) < 0) {
        return binary_searching(mid + 1, high, key);
    } 
	return -1;
} 
