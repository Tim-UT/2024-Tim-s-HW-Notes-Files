/*

Lab 9: ER Madness: Prioritize, Treat, Repeat!

Add Patient (A <ID> <name> <severity>)
Treat Patient (T)
Remove Patient (R ID)
Display Queue (D)
End Program (Q)



*/




#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>     //for string copy

typedef struct person_info {            //build a struct for the patient information
            //<ID> <name> <severity>
            // int  char     int
    int id;
    char name[100];
    int severity;
    struct person_info *next;       // recursive
} Person_info;

typedef struct list {            //build a the list for the patient information
    Person_info *head;          
} List;


int InputLetter (char input) {      // check the input letter
    if (input == 'T') {
        return -1;
    }
    else if (input == 'R') {
        return -2;
    }
    else if (input == 'D') {
        return 1;
    }
    else if (input == 'Q') {
        return 2;
    }
    else if (input == 'A') {
        return 3;
    }
}

/*
Person_info *CreateList(int ID, char NAME[100], int Serevity) {
    Person_info *new_patient = (Person_info *)malloc(sizeof(Person_info));
    if (new_patient != NULL) {
        new_patient->id = ID;
        strcpy(new_patient->name,   NAME);
        new_patient->severity = Serevity;
        new_patient->next = NULL;
      }

    return new_patient;

}
*/

Person_info *create_patient_node(int id, char NAME[], int severity) {       // create a new node for the patient
    Person_info *new_patient_node = malloc(sizeof(Person_info));        //dynamic memory allocation
    if (new_patient_node != NULL) {
        new_patient_node->id = id;
        strcpy(new_patient_node->name, NAME);
        new_patient_node->severity = severity;
        new_patient_node->next = NULL;
    }
    return new_patient_node;
}

bool check_exist (List *list, int id) {     // check if the patient id is already in the list
    bool find = false;
    Person_info *Node = list->head;     //begining with the head
    while (Node != NULL) {          // check until the null
        if (Node->id == id) {
            find = true;
        }
        Node = Node -> next;
    }

    return find;        // return true(duplicate) or false (not duplicate)

}

void Add(List *list, int id, char NAME[], int severity) {       // add a new patient to the list
    if (check_exist(list, id)) {
        printf("Error: Patient %d already exists.\n", id);      // check if the patient id is already in the list

    }
    else {
        Person_info *newAddingNode = create_patient_node(id, NAME, severity);       // create a new node for the patient

        if (list->head == NULL) {
            list->head = newAddingNode;

        }
        
        else {
            Person_info *check = list->head;
            Person_info *previous = NULL;

            for (; check != NULL && check->severity >= newAddingNode->severity; previous = check, check = check->next);


            if (previous == NULL) {
                newAddingNode->next = list->head;
                list->head = newAddingNode;


            } else {
                previous->next = newAddingNode;
                newAddingNode->next = check;

            }

        }
        printf("Patient %d Added.\n", id);

    }

}



void treat(List *list) {            // treat the head of the list
    if (list->head == NULL) {
        printf("Queue is empty.\n");

    } 
    
    else {
        Person_info *head = list->head;
        int id = head->id;

        list->head = head->next;

        printf("Patient %d Treated.\n", id);

        free(head);

    }
}

void display(List *list) {              // display the list
    if (list->head == NULL) {
        printf("Queue is empty.\n");
    }



    for (Person_info *check = list->head; check != NULL; check = check -> next) {       // check until the null
        printf("%s %d\n", check->name, check->severity);

    }
}


void remove_(List *list, int id) {          // remove a patient
    //printf("1st detect\n");

    if (list->head == NULL) {
        //printf("2nd detect\n");
        printf("Error: Patient %d not found.\n", id);       // check if the list is empty
        return;
    }

    if (list->head->id == id) {             //remove the head
        Person_info *temp = list->head;
        list->head = temp->next;
        free(temp);
        printf("Patient %d Removed.\n", id);
        return;
    }

    Person_info *previous, *check;

    for (previous = list->head, check = list->head->next; check != NULL && check->id != id; previous = check, check = check->next);     // check until the null

    if (check == NULL) {
        printf("Error: Patient %d not found.\n", id);
    } else {
        previous->next = check->next;
        free(check);
        printf("Patient %d Removed.\n", id);
    }
}




int main(void) {
    List list;
    list.head= NULL;
    char FirstLetter;
    do {
        scanf("%c",&FirstLetter);

        int status = InputLetter(FirstLetter);
        if (status == 3) {                  // 3 -> add
            int id, severity;
            char name[100];

            scanf(" %d %s %d", &id, name, &severity);
            
            Add(&list, id, name, severity);
        }

        else if (status==-2) {                       // -2 -> delete
            int delete_id = 0;
            scanf("%d", &delete_id);
            remove_(&list, delete_id);
            

        }
        else if (status==-1) {                  // -1 -> treate severist
            treat(&list);

        }
        else if (status==1) {           // 1 -> display
            display(&list);

        }


    } while (FirstLetter != 'Q');

    Person_info *checkForFree;

    for (checkForFree = list.head; checkForFree != NULL; checkForFree = checkForFree->next) {       // check until the null
        Person_info *temp;

        temp = checkForFree;
        free(temp);     // free the memory

    }


    
    
}
