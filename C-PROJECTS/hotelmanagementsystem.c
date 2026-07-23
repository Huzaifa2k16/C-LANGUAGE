#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

int main() {

   int choice, admin_choice;
  int admin_pass = 4567, input_pass, encrypted_input;

   int hotel_id[MAX];
  char name[MAX][50];
  char phone[MAX][20];

   int booking_hotel_id[MAX];
    int room_type[MAX];
   int nights[MAX];
int total_bill[MAX];

int tenant_count = 0;
int booking_count = 0;

  int i, found;
  int charge_per_night;
int room_number;

    srand(time(NULL));

    do {
        printf("\n--- HOTEL MANAGEMENT SYSTEM ---\n");
        printf("1. Register New Tenant\n");
        printf("2. Book Room\n");
        printf("3. Admin Page\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

    switch (choice) {

     case 1:
         printf("Enter Full Name: ");
            scanf(" %[^\n]", name[tenant_count]);

            printf("Enter Phone Number: ");
       scanf(" %[^\n]", phone[tenant_count]);
       hotel_id[tenant_count] = rand() % 9000 + 1000;

            printf("Registration Successful\n");
            printf("Your Hotel ID: %d\n", hotel_id[tenant_count]);

            tenant_count++;
            break;

   case 2:
            printf("Enter your Hotel ID: ");
            int input_id;
            scanf("%d", &input_id);

            found = 0;
            int index = -1;
     for (i = 0; i < tenant_count; i++) {
                if (hotel_id[i] == input_id) {
                    found = 1;
                    index = i;
                    break;
                }
            }

  if (found == 0) {
                printf("Hotel ID not found. Register first.\n");
                break;
            }

printf("\nSelect Room Type:\n");
 printf("1. Single Bed ($50)\n");
  printf("2. Double Bed ($100)\n");
     printf("3. Suite ($200)\n");
   printf("Enter choice: ");
 scanf("%d", &room_type[booking_count]);

            switch (room_type[booking_count]) {
           case 1: charge_per_night = 50; break;
            case 2: charge_per_night = 100; break;
 case 3: charge_per_night = 200; break;
            default:
                printf("Invalid room choice\n");
                break;
            }

            printf("Enter number of nights: ");
            scanf("%d", &nights[booking_count]);

            total_bill[booking_count] = charge_per_night * nights[booking_count];
            booking_hotel_id[booking_count] = input_id;

            room_number = rand() % 900 + 100;

  printf("\n--- BOOKING SUMMARY ---\n");
   printf("Name: %s\n", name[index]);
  printf("Phone: %s\n", phone[index]);
  printf("Room Number: %d\n", room_number);

   if (room_type[booking_count] == 1)
                printf("Room Type: Single Bed\n");
   else if (room_type[booking_count] == 2)
                printf("Room Type: Double Bed\n");
     else
   printf("Room Type: Suite\n");

            printf("Total Bill: $%d\n", total_bill[booking_count]);

            booking_count++;
            break;

    case 3:
            printf("Enter Admin Password: ");
            scanf("%d", &input_pass);

            encrypted_input = input_pass + 3333;

  if (encrypted_input != admin_pass) {
                printf("Access Denied\n");
                break;
            }

   do {
                printf("\n--- ADMIN PANEL ---\n");
    printf("1. Number of people staying\n");
   printf("2. Total rooms booked\n");
    printf("3. Tenants details\n");
   printf("4. Back\n");
   printf("Enter choice: ");
    scanf("%d", &admin_choice);

       switch (admin_choice) {

       case 1:
              printf("Total people staying: %d\n", booking_count);
               break;

      case 2:
         printf("Total rooms booked: %d\n", booking_count);
                    break;

       case 3:
                    for (i = 0; i < booking_count; i++) {
                        printf("\nHotel ID: %d\n", booking_hotel_id[i]);

                        if (room_type[i] == 1)
                            printf("Room Type: Single Bed\n");
                        else if (room_type[i] == 2)
                            printf("Room Type: Double Bed\n");
                        else
                            printf("Room Type: Suite\n");

                        printf("Nights: %d\n", nights[i]);
                        printf("Bill: $%d\n", total_bill[i]);
                    }
               break;
                }

            } while (admin_choice != 4);
            break;

    case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 4);


    return 0;
}
