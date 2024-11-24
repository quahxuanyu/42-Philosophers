#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

// Global balance and mutex
int balance = 0;
pthread_mutex_t mutex;

// Simulate writing the new balance (with 1/4 second delay)
void write_balance(int new_balance)
{
    usleep(250000);
    balance = new_balance;
}

// Simulate reading the balance (with 1/4 second delay)
int read_balance()
{
    usleep(250000);
    return balance;
}

// Deposit function
void *deposit(void *amount)
{
    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Critical section: retrieve and update the balance
    int account_balance = read_balance();
    account_balance += *((int *)amount);
    write_balance(account_balance);

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main()
{
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Output the balance before the deposits
    int before = read_balance();
    printf("Before: %d\n", before);

    // Create two threads to deposit money
    pthread_t thread1, thread2;
    int deposit1 = 300;
    int deposit2 = 200;

    // Start the threads
    pthread_create(&thread1, NULL, deposit, (void *)&deposit1);
    pthread_create(&thread2, NULL, deposit, (void *)&deposit2);

    // Wait for threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Output the balance after the deposits
    int after = read_balance();
    printf("After: %d\n", after);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}

// void *compute(void *num);

// int main(int argc, char *argv[])
// {
// 	pthread_t thread_1;
// 	pthread_t thread_2;
// 	int num;
// 	int num2;

// 	num = 5;
// 	num2 = 10;

// 	// compute((void *) &num);
// 	// compute((void *) &num2);
// 	pthread_create(&thread_1, NULL, compute, (void *)&num);
// 	pthread_create(&thread_2, NULL, compute, (void *)&num2);

// 	pthread_join(thread_1, NULL);
// 	pthread_join(thread_2, NULL);
// }

// void *compute(void *num)
// {
// 	int i;
// 	int sum;
// 	int *new_num;

// 	sum = 0;
// 	new_num = (int *)num;
// 	i = 0;
// 	printf("Threading...\n");
// 	while (++i < 1000000000)
// 		sum += *new_num;
// 	// printf("Number: %i\n", *new_num);
// 	return (NULL);
// }