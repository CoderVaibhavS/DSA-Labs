#include "scheduler.h"
#include "array_deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_deque.h"

// The TIME QUANTUM used by this Round Robin Simulator
#define TIME_QUANTUM 3

static void print_stats(process p);

static process **read_processes_from_file(char *filename, int *num_processes_ptr);

/**
 * DO NOT MODIFY THIS FUNCTION
 * Reads the processes from the file in the format Process_Name Process_id Arrival_time CPU_burst
 * subsequently stores the number of processes in the location pointed by num_processes_ptr
 * @return an array of process pointers read from the file
 */
static process **read_processes_from_file(char *filename, int *num_processes_ptr) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read the number of processes from the first line
    int num_processes;
    fscanf(file, "%d", &num_processes);
    *num_processes_ptr = num_processes;

    // Allocate memory for the process pointers
    process **processes = malloc(num_processes * sizeof(process *));
    if (processes == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for processes\n");
        exit(EXIT_FAILURE);
    }

    // Read each process from the file
    for (int i = 0; i < num_processes; i++) {
        process *p = malloc(sizeof(process));
        if (p == NULL) {
            fprintf(stderr, "Error: Failed to allocate memory for process\n");
            exit(EXIT_FAILURE);
        }

        // Read the process data from the file
        char name[32];
        unsigned int pid, arrival, cpu_burst;
        fscanf(file, "%s %u %u %u", name, &pid, &arrival, &cpu_burst);
        p->name = strdup(name);
        p->pid = pid;
        p->arrival = arrival;
        p->cpu_burst = cpu_burst;

        // Initialize the other process fields to 0
        p->turnaround = 0;
        p->wait = 0;
        p->remaining_time = cpu_burst;

        processes[i] = p;
    }

    fclose(file);
    return processes;
}

process remove_process(linked_deque *ld, process *p, int *time) {
    remove_last_linked_deque(ld, p);
    *time += (p->remaining_time) > TIME_QUANTUM ? TIME_QUANTUM : p->remaining_time;
    p->turnaround = *time - p->arrival;
    p->wait = p->turnaround - p->cpu_burst;
    p->remaining_time -= (p->remaining_time) > TIME_QUANTUM ? TIME_QUANTUM : p->remaining_time;
    if(p->remaining_time <= 0) {
        print_stats(*p);
    }
    return *p;
}

void add_process(linked_deque *ld, process p) {
    add_first_linked_deque(ld, p);
}

void visualize_round_robin(char *path) {
    int num_processes;
    process **processes = read_processes_from_file(path, &num_processes);

    printf("Number of processes: %d\n", num_processes);
    printf("%-10s%-15s%-15s%-15s%-15s\n", "Process", "Arrival Time", "Burst Time", "Waiting Time", "Turnaround Time");

    linked_deque *ld = create_linked_process_deque();

    // COMPLETE using the ld for storing processes as described
    add_process(ld, *(processes[0]));
    process p;
    process removed_process;
    int time = 0;
    int i = 1;
    int c = 12;
    // while(c--) {
    while(!is_empty_linked_deque(ld)) {
        removed_process = remove_process(ld, &p, &time);
        while(i<num_processes) {
            if(processes[i]->arrival <= time) {
                add_process(ld, *(processes[i++]));
            }
            else
                break;
        }
        if(p.remaining_time > 0) {
            add_process(ld, removed_process);
        }
    }

    // Free the allocated memory
    for (int i = 0; i < num_processes; i++) {
        free(processes[i]->name);
        free(processes[i]);
    }
    free(processes);
}



// Prints the stats for the process p to stdout
static void print_stats(process p) {
    printf("%-10s%-15d%-15d%-15d%-15d\n",
           p.name,
           p.arrival,
           p.cpu_burst,
           p.wait,
           p.turnaround);
}