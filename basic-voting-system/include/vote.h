#ifndef VOTE_H
#define VOTE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5
#define MAX_NAME_LENGTH 200

// Candidate structure
typedef struct my_candidate
{
    char *name;
    int votes;
} Candidate;

// Function prototypes

/**
 * @brief This function displays the list of candidates
 *
 * @param candidates The array of candidates
 * @param num_candidates The number of candidates
 *
 * @return void
 */

void display_candidates(Candidate *candidates, int num_candidates);

/**
 * @brief This function allows the user to vote for a candidate
 *
 * @param candidates  The array of candidates
 * @param num_candidates The number of candidates
 *
 * @return void
 */

void vote(Candidate *candidates, int num_candidates);

/**
 * @brief This function displays the results of the election
 *
 * @param candidates  The array of candidates
 * @param num_candidates  The number of candidates
 *
 * @return void
 */

void display_results(Candidate *candidates, int num_candidates);

#endif