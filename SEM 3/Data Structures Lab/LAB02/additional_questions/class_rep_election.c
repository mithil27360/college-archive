#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void displayResults(int *votes, char **names, int candidates, int index)
{
    if(index < candidates)
    {
        printf("%s: %d votes\n", *(names + index), *(votes + index + 1));
        displayResults(votes, names, candidates, index + 1);
    }
}

int findWinner(int *votes, int candidates, int index, int maxVotes, int winner)
{
    if(index > candidates)
        return winner;
    
    if(*(votes + index) > maxVotes)
    {
        maxVotes = *(votes + index);
        winner = index;
    }
    
    return findWinner(votes, candidates, index + 1, maxVotes, winner);
}

int main()
{
    int students, candidates, i, vote, winnerIndex;
    int *votes;
    char **names;
    char start;
    
    printf("Enter number of students: ");
    scanf("%d", &students);
    
    printf("Enter number of candidates: ");
    scanf("%d", &candidates);
    
    votes = (int*)calloc(candidates + 1, sizeof(int));
    
    names = (char**)calloc(candidates, sizeof(char*));
    for(i = 0; i < candidates; i++)
        *(names + i) = (char*)calloc(50, sizeof(char));
    
    printf("Enter candidate names:\n");
    for(i = 0; i < candidates; i++)
    {
        printf("Candidate %d: ", i + 1);
        scanf("%s", *(names + i));
    }
    
    printf("\nPress S to start voting: ");
    scanf(" %c", &start);
    
    if(start == 'S' || start == 's')
    {
        for(i = 1; i <= students; i++)
        {
            printf("\nStudent %d, enter vote (1-%d): ", i, candidates);
            scanf("%d", &vote);
            
            if(vote >= 1 && vote <= candidates)
            {
                (*(votes + vote))++;
                printf("Vote recorded\n");
            }
            else
            {
                (*votes)++;
                printf("Foul vote\n");
            }
        }
    }
    
    printf("\n--- Results ---\n");
    displayResults(votes, names, candidates, 0);
    printf("Foul votes: %d\n", *votes);
    
    winnerIndex = findWinner(votes, candidates, 1, 0, 0);
    
    if(winnerIndex > 0)
        printf("\nWinner: %s with %d votes\n", *(names + winnerIndex - 1), *(votes + winnerIndex));
    else
        printf("\nNo winner\n");
    
    for(i = 0; i < candidates; i++)
        free(*(names + i));
    free(names);
    free(votes);
    
    return 0;
}