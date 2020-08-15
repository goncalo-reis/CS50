#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Compare vote with name of candidates
        if (strcmp(name, candidates[i].name) == 0)
        {
            // Update number of votes on chosen candidate
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Higher amount of votes on a candidate
    int higher_vote = 0;
    
    // Array of election winners
    string winners[candidate_count];

    // Find number of votes of candidate(s) with higher number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > higher_vote)
        {
            higher_vote = candidates[i].votes;
        }
    }
    int j = 0;
    // Populate winners array with name of candidate(s) whose number of votes equal the higher number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == higher_vote)
        {
            winners[j] = candidates[i].name;
            j++;
        }
    }
    // Loop through and print winner(s) on different lines
    for (int i = 0; i < j; i++)
    {
        printf("%s\n", winners[i]);
    }
}

