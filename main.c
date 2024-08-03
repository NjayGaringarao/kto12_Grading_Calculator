#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <conio.h>

char input0[100];          // raw input from user (char value).
int inCount;               // nag che check kung sakto lang ba nilagay ni user.
int inputA;                // Converted input from user (char input0 to int value) for curriculum selection.
char inputB;               // Converted input from user (char input0 to int value) for calculation mode.
char wrong, wrong1, slash; // para sa mga user na may pasobra.

float grades[10] = {0};     // reusable array for grades in a subjects.
float gradesMapeh[4] = {0}; // array for mapeh grades
int writtenS[10];
int performanceS[10];
int pT[2];
float average;

float writtenComponentTotal;
float performanceComponentTotal;
float pTComponentTotal;

// STRINGS
char *subject1[8] = {"Filipino                       ",
                     "English                        ",
                     "Mathematics                    ",
                     "Science                        ",
                     "Araling Panlipunan             ",
                     "Edukasyon sa Pagpapakatao      ",
                     "EPP                            ",
                     "MAPEH                          "};

char *subjectMapeh[4] = {" - Music              ",
                         " - Arts               ",
                         " - Physical Education ",
                         " - Health             "};

char *subject2[7] = {"Oral Communication in Context                      ",
                     "Kom. at Pananaliksik sa Kulturang Pilipino         ",
                     "General Mathematics                                ",
                     "Earth and Life Science                             ",
                     "Personal Development                               ",
                     "Understanding The Self                             ",
                     "Physical Education And Health                      "};

char *subject3[8] = {"Reading and Writing Skills                         ",
                     "Teksto Sa Pananaliksik                             ",
                     "Statics And Probability                            ",
                     "Physical Science                                   ",
                     "Physical Education And Health                      ",
                     "Business Math                                      ",
                     "Organization And Management                        ",
                     "Fundamentals Of Accounting                         "};

char *subject4[7] = {"21st Cen. Liter. from The PH And The World         ",
                     "Intro To The Philosophy Of The Human Person        ",
                     "Contemp. PH Arts From The Regions                  ",
                     "Media And Information Literacy                     ",
                     "Physical Education And Health                      ",
                     "Fundamentals Of Accounting                         ",
                     "Business Finance                                   "};

char *subject5[5] = {"Physical Education And Health                        ",
                     "Applied Economics                                    ",
                     "Business Ethics And Social Responsibility            ",
                     "Businesss Marketing                                  ",
                     "Business Enterprise Simulation                       "};

void userInputWritten()
{
    int actCount;
    float totalScore = 0.0;
    float totalHighScore = 0.0;

    printf("\n[Written Works]");
    printf("\n");
    printf("How many activities will be computed?[1 to 50]: ");

    while (fgets(input0, sizeof(input0), stdin))
    {
        input0[strcspn(input0, "\n")] = '\0';

        int validInput = 1; // Flag variable if input is valid

        for (int j = 0; input0[j] != '\0'; j++)
        {
            if (!isdigit(input0[j]))
            {
                validInput = 0;
                break;
            }
        }

        if (validInput && sscanf(input0, "%d", &actCount) == 1)
        {
            if (actCount >= 1 && actCount <= 50)
            {
                break;
            }
        }

        printf("\n[Invalid Input] Try Again: ");
    }

    printf("\nInstruction: Write the score in each activity in the");
    printf("\n             format of: Raw Score/Highest Possible");
    printf("\n             Score (eg: "
           "9/10"
           " ) then press ENTER");

    for (int i = 0; i < actCount; i++)
    {

        printf("\nACTIVITY %d: ", i + 1);

        // INPUT
        while (true)
        {
            // fflush(stdin); // kase sa unang loop "[Wrong Input] Try Again:" agad
            fgets(input0, sizeof(input0), stdin);
            inCount = sscanf(input0, "%d%c%d%c%c", &writtenS[i], &slash, &writtenS[i + 50], &wrong, &wrong1);

            if (inCount == 4 && slash == '/' && writtenS[i] <= writtenS[i + 50] && strspn(input0, "0123456789/") == strlen(input0) - 1)
            {
                break;
            }
            else
            {
                printf("[Wrong Input] Try Again: ");
            }
        }
    }

    // Totalling Activities
    for (int i = 0; i < actCount; i++)
    {
        totalScore += writtenS[i];
    }
    for (int i = 50; i < actCount + 50; i++)
    {
        totalHighScore += writtenS[i];
    }

    writtenComponentTotal = ((totalScore / totalHighScore) * 100);

    printf("\n");
    printf("\nTotal Possible Score   : %.0f point/s", totalHighScore);
    printf("\nTotal Raw Score        : %.0f point/s", totalScore);
    printf("\nComponent Total        : %.2f%%", writtenComponentTotal);
}
void userInputPerformance()
{

    int actCount;
    float totalScore = 0.0;
    float totalHighScore = 0.0;

    printf("\n");
    printf("\n[Performance Task]");
    printf("\n");
    printf("How many activities will be computed?[1 to 50]: ");

    while (fgets(input0, sizeof(input0), stdin))
    {
        input0[strcspn(input0, "\n")] = '\0';

        int validInput = 1; // Flag variable if input is valid

        for (int j = 0; input0[j] != '\0'; j++)
        {
            if (!isdigit(input0[j]))
            {
                validInput = 0;
                break;
            }
        }

        if (validInput && sscanf(input0, "%d", &actCount) == 1)
        {
            if (actCount >= 1 && actCount <= 50)
            {
                break;
            }
        }

        printf("\n[Invalid Input] Try Again: ");
    }

    printf("\nInstruction: Write the score in each activity in the");
    printf("\n             format of: Raw Score/Highest Possible");
    printf("\n             Score (eg: "
           "9/10"
           " ) then press ENTER");

    for (int i = 0; i < actCount; i++)
    {

        printf("\nACTIVITY %d: ", i + 1);

        // INPUT
        while (true)
        {
            // fflush(stdin); // kase sa unang loop "[Wrong Input] Try Again:" agad
            fgets(input0, sizeof(input0), stdin);
            inCount = sscanf(input0, "%d%c%d%c%c", &performanceS[i], &slash, &performanceS[i + 50], &wrong, &wrong1);

            if (inCount == 4 && slash == '/' && performanceS[i] <= performanceS[i + 50] && strspn(input0, "0123456789/") == strlen(input0) - 1)
            {
                break;
            }
            else
            {
                printf("[Wrong Input] Try Again: ");
            }
        }
    }

    // Totalling Activities
    for (int i = 0; i < actCount; i++)
    {
        totalScore += performanceS[i];
    }
    for (int i = 50; i < actCount + 50; i++)
    {
        totalHighScore += performanceS[i];
    }

    performanceComponentTotal = ((totalScore / totalHighScore) * 100);

    printf("\n");
    printf("\nTotal Possible Score   : %.0f point/s", totalHighScore);
    printf("\nTotal Raw Score        : %.0f point/s", totalScore);
    printf("\nComponent Total        : %.2f%%", performanceComponentTotal);
}
void userInputQA()
{
    printf("\n");
    printf("\n[Quarterly Assessment] ");
    printf("\nInstruction: Write the score in each activity in the");
    printf("\n             format of: Raw Score/Highest Possible");
    printf("\n             Score (eg: "
           "9/10"
           " ) then press ENTER");
    printf("\n ");
    printf("\nFinal Examination: ");

    while (true)
    {
        fgets(input0, sizeof(input0), stdin);
        inCount = sscanf(input0, "%d%c%d%c%c", &pT[0], &slash, &pT[1], &wrong, &wrong1);

        if (inCount == 4 && slash == '/' && pT[0] <= pT[1] && strspn(input0, "0123456789/") == strlen(input0) - 1)
        {
            break;
        }
        else
        {
            printf("[Wrong Input] Try Again: ");
        }
    }

    float totalFirstSemScore = pT[0];
    float totalSecondSemScore = pT[1];

    pTComponentTotal = ((totalFirstSemScore / totalSecondSemScore) * 100);

    while (pTComponentTotal > 100)
    {
        printf("\nSomething is Wrong, Please input the score again.");
        userInputQA();
    }
    printf("\nComponent Total: %.2f%%", pTComponentTotal);
}

void mapeh()
{

    printf("\n");
    printf("\n%s", subject1[7]);
    for (int i = 0; i < 4; i++)
    {
        printf("\n%s", subjectMapeh[i]);
        userInputWritten();
        userInputPerformance();
        userInputQA();
        gradesMapeh[i] = (writtenComponentTotal * 0.3) + (performanceComponentTotal * 0.5) + (pTComponentTotal * 0.2);
        printf("\nMAPEH COMPONENT%s: %.2f", subjectMapeh[i], gradesMapeh[i]);
        printf("\n");
    }
    grades[7] = (gradesMapeh[0] + gradesMapeh[1] + gradesMapeh[2] + gradesMapeh[3]) / 4;
}
void curriculum1a()
{
    char userSubject;
    printf("\n----------------------------------------------------------------");
    printf("\nSubjects inside Grade 1 to 10: ");
    printf("\n");

    for (int i = 0; i < 8; i++)
    {
        printf("\n  %d %s", i + 1, subject1[i]);
    }
    // INPUTS AND SELECTION
    printf("\n");
    printf("\nEnter the number that corresponds to your choice: ");

    fgets(input0, sizeof(input0), stdin);
    inCount = strlen(input0);
    userSubject = input0[0] - '0';

    while (inCount != 2 || userSubject < 1 || userSubject > 8)
    {
        printf("\n[Wrong Input] Try Again: ");
        fgets(input0, sizeof(input0), stdin);
        inCount = strlen(input0);
        userSubject = input0[0] - '0';
    }

    // OPERATION
    if (userSubject == 8)
    {
        mapeh();
    }
    else
    {
        printf("\n%s", subject1[userSubject - 1]);
        printf("\n");

        userInputWritten();
        userInputPerformance();
        userInputQA();

        grades[userSubject - 1] = (writtenComponentTotal * 0.3) + (performanceComponentTotal * 0.5) + (pTComponentTotal * 0.2);
        printf("\n");
    }

    printf("\n%s: %.2f", subject1[userSubject - 1], grades[userSubject - 1]);
    if (grades[userSubject - 1] < 75)
    {
        printf(" - FAILED");
    }
    else
    {
        printf(" - PASSED");
    }
    printf("\n");
}
void curriculum1b()
{
    for (int i = 0; i < 7; i++)
    {
        printf("\n----------------------------------------------------------------");
        printf("\n - %s: ", subject1[i]);
        userInputWritten();
        userInputPerformance();
        userInputQA();

        grades[i] = (writtenComponentTotal * 0.3) + (performanceComponentTotal * 0.5) + (pTComponentTotal * 0.2);

        printf("\n%s: %.2f%%", subject1[i], grades[i]);

        if (grades[i] < 75)
        {
            printf(" - FAILED");
        }
        else
        {
            printf(" - PASSED");
        }
        printf("\n----------------------------------------------------------------");
    }

    mapeh();

    for (int i = 0; i < 8; i++)
    {
        printf("\n%s: %.2f", subject1[i], grades[i]);
    }

    average = (grades[0] + grades[1] + grades[2] + grades[3] + grades[4] + grades[5] + grades[6] + grades[7]) / 8;
    printf("\nAVERAGE                       : %.2f%%", average);

    if (average < 75)
    {
        printf(" - FAILED");
    }
    else
    {
        printf(" - PASSED");
    }
}
void curriculum1c()
{
    printf("\n----------------------------------------------------------------");
    printf("\nInstruction: Enter the grades that correspond to the subjects.\n");

    for (int i = 0; i < 8; i++)
    {
        printf("\n%s: ", subject1[i]);
        while (fgets(input0, sizeof(input0), stdin) != NULL)
        {
            input0[strcspn(input0, "\n")] = '\0';

            int j;
            for (j = 0; input0[j] != '\0'; j++)
            {
                if (!isdigit(input0[j]))
                {
                    printf("\n[Invalid Input] Try Again: ");
                    break;
                }
            }
            if (input0[j] == '\0')
            {
                if (sscanf(input0, "%f", &grades[i]) == 1)
                {
                    if (grades[i] >= 50 && grades[i] <= 100)
                    {
                        break;
                    }
                    else
                    {
                        printf("\n[Invalid Input] Try Again: ");
                    }
                }
                else
                {
                    printf("\n[Invalid Input] Try Again: ");
                }
            }
        }
    }

    float average = 0;
    for (int i = 0; i < 8; i++)
    {
        average += grades[i];
    }
    average /= 8;

    printf("\nAVERAGE                       : %.2f%%", average);

    if (average < 75)
    {
        printf(" - FAILED");
    }
    else
    {
        printf(" - PASSED");
    }
}

void curriculum2a()
{
    char userSubject;
    printf("\n----------------------------------------------------------------");
    printf("\nSubjects inside Grade 11 ABM First Semester: ");

    for (int i = 0; i < 7; i++)
    {
        printf("\n%d %s", i + 1, subject2[i]);
    }

    printf("\n");
    printf("\nEnter the number that corresponds to your choice: ");

    fgets(input0, sizeof(input0), stdin);
    inCount = strlen(input0);
    userSubject = input0[0] - '0';

    while (inCount != 2 || userSubject < 1 || userSubject > 7)
    {
        printf("\n[Wrong Input] Try Again: ");
        fgets(input0, sizeof(input0), stdin);
        inCount = strlen(input0);
        userSubject = input0[0] - '0';
    }

    printf("\n%s", subject2[userSubject - 1]);
    printf("\n");

    userInputWritten();
    userInputPerformance();
    userInputQA();

    grades[userSubject - 1] = (writtenComponentTotal * 0.25) + (performanceComponentTotal * 0.50) + (pTComponentTotal * 0.25);
    printf("\n");
    printf("\n%s: %.2f", subject2[userSubject - 1], grades[userSubject - 1]);

    if (grades[userSubject - 1] < 75)
    {
        printf(" - FAILED");
    }
    else
    {
        printf(" - PASSED");
    }
    printf("\n");
}
void curriculum2b()
{
    for (int i = 0; i < 7; i++)
    {
        printf("\n----------------------------------------------------------------");
        printf("\n - %s: ", subject2[i]);

        userInputWritten();
        userInputPerformance();
        userInputQA();

        grades[i] = (writtenComponentTotal * 0.25) + (performanceComponentTotal * 0.50) + (pTComponentTotal * 0.25);

        printf("\n%s: %.2f%%", subject2[i], grades[i]);

        if (grades[i] < 75)
        {
            printf(" - FAILED");
        }
        else
        {
            printf(" - PASSED");
        }
        printf("\n----------------------------------------------------------------");
    }
    for (int i = 0; i < 7; i++)
    {
        printf("\n%s: %.2f", subject2[i], grades[i]);
    }

    average = (grades[0] + grades[1] + grades[2] + grades[3] + grades[4] + grades[5] + grades[6]) / 7;
    printf("\nAVERAGE                                           : %.2f%%", average);

    if (average < 75)
    {
        printf(" - FAILED");
    }
    else
    {
        printf(" - PASSED");
    }
}
void curriculum2c()
{
    printf("\n----------------------------------------------------------------");
    printf("\nInstruction: Enter the grades that correspond to the subjects.\n");

    for (int i = 0; i < 7; i++)
    {
        printf("\n%s: ", subject2[i]);
        while (fgets(input0, sizeof(input0), stdin) != NULL)
        {
            input0[strcspn(input0, "\n")] = '\0';

            int j;
            for (j = 0; input0[j] != '\0'; j++)
            {
                if (!isdigit(input0[j]))
                {
                    printf("\n[Invalid Input] Try Again: ");
                    break;
                }
            }

            if (input0[j] == '\0')
            {
                if (sscanf(input0, "%f", &grades[i]) == 1)
                {
                    if (grades[i] >= 50 && grades[i] <= 100)
                    {
                        break;
                    }
                    else
                    {
                        printf("\n[Invalid Input] Try Again: ");
                    }
                }
                else
                {
                    printf("\n[Invalid Input] Try Again: ");
                }
            }
        }
    }

    float average = 0;
    for (int i = 0; i < 7; i++)
    {
        average += grades[i];
    }
    average /= 7;

    printf("\nAVERAGE                       : %.2f%%", average);

    if (average < 75)
    {
        printf(" - FAILED");
    }
    else
    {
        printf(" - PASSED");
    }
}

void curriculum3a()
{
    char userSubject;
    printf("\n----------------------------------------------------------------");
    printf("\nSubjects inside Grade 11 2nd Semester: ");
    printf("\n");

    for (int i = 0; i < 8; i++)
    {
        printf("\n  %d %s", i + 1, subject3[i]);
    }

    printf("\n");
    printf("\nEnter the number that corresponds to your choice: ");

    fgets(input0, sizeof(input0), stdin);
    inCount = strlen(input0);
    userSubject = input0[0] - '0';

    while (inCount != 2 || userSubject < 1 || userSubject > 8)
    {
        printf("\n[Wrong Input] Try Again: ");
        fgets(input0, sizeof(input0), stdin);
        inCount = strlen(input0);
        userSubject = input0[0] - '0';
    }

    printf("\n%s", subject3[userSubject - 1]);
    printf("\n");

    userInputWritten();
    userInputPerformance();
    userInputQA();

    if (userSubject < 5 && userSubject > 9)
    {
        grades[userSubject] = (writtenComponentTotal * 0.35) + (performanceComponentTotal * 0.40) + (pTComponentTotal * 0.25);
    }
    else
    {
        grades[userSubject] = (writtenComponentTotal * 0.25) + (performanceComponentTotal * 0.5) + (pTComponentTotal * 0.25);
    }

    printf("\n");
    printf("\n%s: %.2f", subject3[userSubject - 1], grades[userSubject - 1]);

    if (grades[userSubject - 1] < 75)
    {
        printf(" - FAILED");
    }
    else
    {
        printf(" - PASSED");
    }
    printf("\n");
}
void curriculum3b()
{
    for (int i = 0; i < 8; i++)
    {
        printf("\n----------------------------------------------------------------");
        printf("\n - %s: ", subject3[i]);
        userInputWritten();
        userInputPerformance();
        userInputQA();

        if (i < 8 && i > 4)
        {
            grades[i] = (writtenComponentTotal * 0.35) + (performanceComponentTotal * 0.40) + (pTComponentTotal * 0.25);
        }
        else
        {
            grades[i] = (writtenComponentTotal * 0.25) + (performanceComponentTotal * 0.5) + (pTComponentTotal * 0.25);
        }

        printf("\n%s: %.2f%%", subject3[i], grades[i]);

        if (grades[i] < 75)
        {
            printf(" - FAILED");
        }
        else
        {
            printf(" - PASSED");
        }
        printf("\n----------------------------------------------------------------");
    }
    for (int i = 0; i < 8; i++)
    {
        printf("\n%s: %.2f", subject3[i], grades[i]);
    }

    average = (grades[0] + grades[1] + grades[2] + grades[3] + grades[4] + grades[5] + grades[6] + grades[7]) / 8;
    printf("\nAVERAGE                       : %.2f%%", average);

    if (average < 75)
    {
        printf(" - FAILED");
    }
    else
    {
        printf(" - PASSED");
    }
}
void curriculum3c()
{
    printf("\n----------------------------------------------------------------");
    printf("\nInstruction: Enter the grades that correspond to the subjects.\n");

    for (int i = 0; i < 8; i++)
    {
        printf("\n%s: ", subject3[i]);
        while (fgets(input0, sizeof(input0), stdin) != NULL)
        {
            input0[strcspn(input0, "\n")] = '\0';

            int j;
            for (j = 0; input0[j] != '\0'; j++)
            {
                if (!isdigit(input0[j]))
                {
                    printf("\n[Invalid Input] Try Again: ");
                    break;
                }
            }

            if (input0[j] == '\0')
            {
                if (sscanf(input0, "%f", &grades[i]) == 1)
                {
                    if (grades[i] >= 50 && grades[i] <= 100)
                    {
                        break;
                    }
                    else
                    {
                        printf("\n[Invalid Input] Try Again: ");
                    }
                }
                else
                {
                    printf("\n[Invalid Input] Try Again: ");
                }
            }
        }
    }

    float average = 0;
    for (int i = 0; i < 8; i++)
    {
        average += grades[i];
    }
    average /= 8;

    printf("\nAVERAGE                       : %.2f%%", average);

    if (average < 75)
    {
        printf(" - FAILED");
    }
    else
    {
        printf(" - PASSED");
    }
}

void curriculum4a()
{
    char userSubject;
    printf("\n----------------------------------------------------------------");
    printf("\nSubjects inside Grade 11 ABM First Semester: ");

    for (int i = 0; i < 7; i++)
    {
        printf("\n%d %s", i + 1, subject4[i]);
    }

    printf("\n");
    printf("\nEnter the number that corresponds to your choice: ");

    fgets(input0, sizeof(input0), stdin);
    inCount = strlen(input0);
    userSubject = input0[0] - '0';

    while (inCount != 2 || userSubject < 1 || userSubject > 7)
    {
        printf("\n[Wrong Input] Try Again: ");
        fgets(input0, sizeof(input0), stdin);
        inCount = strlen(input0);
        userSubject = input0[0] - '0';
    }

    printf("\n%s", subject4[userSubject - 1]);
    printf("\n");

    userInputWritten();
    userInputPerformance();
    userInputQA();

    if (userSubject < 8 && userSubject > 5)
    {
        grades[userSubject] = (writtenComponentTotal * 0.35) + (performanceComponentTotal * 0.40) + (pTComponentTotal * 0.25);
    }
    else
    {
        grades[userSubject] = (writtenComponentTotal * 0.25) + (performanceComponentTotal * 0.5) + (pTComponentTotal * 0.25);
    }

    printf("\n");
    printf("\n%s: %.2f", subject4[userSubject - 1], grades[userSubject - 1]);

    if (grades[userSubject - 1] < 75)
    {
        printf(" - FAILED");
    }
    else
    {
        printf(" - PASSED");
    }
    printf("\n");
}
void curriculum4b()
{
    for (int i = 0; i < 7; i++)
    {
        printf("\n----------------------------------------------------------------");
        printf("\n - %s: ", subject4[i]);
        userInputWritten();
        userInputPerformance();
        userInputQA();

        if (i < 7 && i > 2)
        {
            grades[i] = (writtenComponentTotal * 0.35) + (performanceComponentTotal * 0.40) + (pTComponentTotal * 0.25);
        }
        else
        {
            grades[i] = (writtenComponentTotal * 0.25) + (performanceComponentTotal * 0.5) + (pTComponentTotal * 0.25);
        }

        printf("\n%s: %.2f%%", subject4[i], grades[i]);

        if (grades[i] < 75)
        {
            printf(" - FAILED");
        }
        else
        {
            printf(" - PASSED");
        }
        printf("\n----------------------------------------------------------------");
    }
    for (int i = 0; i < 7; i++)
    {
        printf("\n%s: %.2f", grades[i], grades[i]);
    }

    average = (grades[0] + grades[1] + grades[2] + grades[3] + grades[4] + grades[5] + grades[6]) / 7;
    printf("\nAVERAGE                       : %.2f%%", average);

    if (average < 75)
    {
        printf(" - FAILED");
    }
    else
    {
        printf(" - PASSED");
    }
}
void curriculum4c()
{
    printf("\n----------------------------------------------------------------");
    printf("\nInstruction: Enter the grades that correspond to the subjects.\n");

    for (int i = 0; i < 7; i++)
    {
        printf("\n%s: ", subject4[i]);
        while (fgets(input0, sizeof(input0), stdin) != NULL)
        {
            input0[strcspn(input0, "\n")] = '\0';

            int j;
            for (j = 0; input0[j] != '\0'; j++)
            {
                if (!isdigit(input0[j]))
                {
                    printf("\n[Invalid Input] Try Again: ");
                    break;
                }
            }

            if (input0[j] == '\0')
            {
                if (sscanf(input0, "%f", &grades[i]) == 1)
                {
                    if (grades[i] >= 50 && grades[i] <= 100)
                    {
                        break;
                    }
                    else
                    {
                        printf("\n[Invalid Input] Try Again: ");
                    }
                }
                else
                {
                    printf("\n[Invalid Input] Try Again: ");
                }
            }
        }
    }

    float average = 0;
    for (int i = 0; i < 7; i++)
    {
        average += grades[i];
    }
    average /= 7;

    printf("\nAVERAGE                                           : %.2f%%", average);

    if (average < 75)
    {
        printf(" - FAILED");
    }
    else
    {
        printf(" - PASSED");
    }
}

void curriculum5a()
{
    char userSubject;
    printf("\n----------------------------------------------------------------");
    printf("\nSubjects inside Grade 11 ABM First Semester: ");

    for (int i = 0; i < 5; i++)
    {
        printf("\n%d %s", i + 1, subject5[i]);
    }

    printf("\n");
    printf("\nEnter the number that corresponds to your choice: ");

    fgets(input0, sizeof(input0), stdin);
    inCount = strlen(input0);
    userSubject = input0[0] - '0';

    while (inCount != 2 || userSubject < 1 || userSubject > 5)
    {
        printf("\n[Wrong Input]  Again: ");
        fgets(input0, sizeof(input0), stdin);
        inCount = strlen(input0);
        userSubject = input0[0] - '0';
    }

    printf("\n%s", subject5[userSubject - 1]);
    printf("\n");

    userInputWritten();
    userInputPerformance();
    userInputQA();

    if (userSubject < 6 && userSubject > 1)
    {
        grades[userSubject] = (writtenComponentTotal * 0.35) + (performanceComponentTotal * 0.40) + (pTComponentTotal * 0.25);
    }
    else
    {
        grades[userSubject] = (writtenComponentTotal * 0.25) + (performanceComponentTotal * 0.5) + (pTComponentTotal * 0.25);
    }
    printf("\n");
    printf("\n%s: %.2f", subject5[userSubject - 1], grades[userSubject - 1]);

    if (grades[userSubject - 1] < 75)
    {
        printf(" - FAILED");
    }
    else
    {
        printf(" - PASSED");
    }
    printf("\n");
}
void curriculum5b()
{
    for (int i = 0; i < 5; i++)
    {
        printf("\n----------------------------------------------------------------");
        printf("\n - %s: ", subject5[i]);
        userInputWritten();
        userInputPerformance();
        userInputQA();

        if (i < 5 && i > 0)
        {
            grades[i] = (writtenComponentTotal * 0.35) + (performanceComponentTotal * 0.40) + (pTComponentTotal * 0.25);
        }
        else
        {
            grades[i] = (writtenComponentTotal * 0.25) + (performanceComponentTotal * 0.5) + (pTComponentTotal * 0.25);
        }

        printf("\n%s: %.2f%%", subject5[i], grades[i]);

        if (grades[i] < 75)
        {
            printf(" - FAILED");
        }
        else
        {
            printf(" - PASSED");
        }
        printf("\n----------------------------------------------------------------");
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\n%s: %.2f", subject5[i], grades[i]);
    }

    average = (grades[0] + grades[1] + grades[2] + grades[3] + grades[4]) / 5;
    printf("\nAVERAGE                       : %.2f%%", average);

    if (average < 75)
    {
        printf(" - FAILED");
    }
    else
    {
        printf(" - PASSED");
    }
}
void curriculum5c()
{
    printf("\n----------------------------------------------------------------");
    printf("\nInstruction: Enter the grades that correspond to the subject.\n");

    for (int i = 0; i < 5; i++)
    {
        printf("\n%s: ", subject5[i]);
        while (fgets(input0, sizeof(input0), stdin) != NULL)
        {
            input0[strcspn(input0, "\n")] = '\0';

            int j;
            for (j = 0; input0[j] != '\0'; j++)
            {
                if (!isdigit(input0[j]))
                {
                    printf("\n[Invalid Input] Try Again: ");
                    break;
                }
            }

            if (input0[j] == '\0')
            {
                if (sscanf(input0, "%f", &grades[i]) == 1)
                {
                    if (grades[i] >= 50 && grades[i] <= 100)
                    {
                        break;
                    }
                    else
                    {
                        printf("\n[Invalid Input] Try Again: ");
                    }
                }
                else
                {
                    printf("\n[Invalid Input] Try Again: ");
                }
            }
        }
    }
    float average = 0;
    for (int i = 0; i < 5; i++)
    {
        average += grades[i];
    }
    average /= 5;

    printf("\nAVERAGE                                           : %.2f%%", average);

    if (average < 75)
    {
        printf(" - FAILED");
    }
    else
    {
        printf(" - PASSED");
    }
}

void semesterChoices()
{

    printf("\n Instruction: Select prefered semester type by entering the");
    printf("\n              correct number that corresponds to your choice.");
    printf("\n");
    printf("\n     1 for Grade 1 to 10");
    printf("\n     2 for Grade 11 ABM 1st Semester");
    printf("\n     3 for Grade 11 ABM 2nd Semester");
    printf("\n     4 for Grade 12 ABM 1st Semester");
    printf("\n     5 for Grade 12 ABM 2nd Semester");
    printf("\n");
    printf("\nEnter your choice: ");

    fgets(input0, sizeof(input0), stdin);
    inCount = strlen(input0);
    inputA = input0[0] - '0';

    while (inCount != 2 || inputA < 1 || inputA > 5)
    {
        printf("\n[Wrong Input] Try Again: ");
        fgets(input0, sizeof(input0), stdin);
        inCount = strlen(input0);
        inputA = input0[0] - '0';
    }

    printf("\n----------------------------------------------------------------");

    printf("\nInstruction: Choose computing mode by inputing the correct let-");
    printf("\n             ter that corresponds to your choice:");
    printf("\n");
    printf("\n     a for computing grades for only one subject.");
    printf("\n     b for computing grades for the Whole Semester.");
    printf("\n     c for computing only the average grade. (Note: Grades for");
    printf("\n       every subject in the chosen curriculum is required).");
    printf("\n");
    printf("\nEnter your choice: ");

    fgets(input0, sizeof(input0), stdin);
    inCount = strlen(input0);
    inputB = input0[0];

    // Input Verification
    while (inCount != 2 || inputB != 'a' && inputB != 'b' && inputB != 'c')
    {
        printf("\n[Wrong Input] Try Again: ");
        fgets(input0, sizeof(input0), stdin);
        inCount = strlen(input0);
        inputB = input0[0];
    }

    // hub papunta sa ibat ibang functions
    if (inputA == 1)
    {
        if (inputB == 'a')
        {
            curriculum1a();
        }
        else if (inputB == 'b')
        {
            curriculum1b();
        }
        else
        {
            curriculum1c();
        }
    }
    else if (inputA == 2)
    {
        if (inputB == 'a')
        {
            curriculum2a();
        }
        else if (inputB == 'b')
        {
            curriculum2b();
        }
        else
        {
            curriculum2c();
        }
    }
    else if (inputA == 3)
    {
        if (inputB == 'a')
        {
            curriculum3a();
        }
        else if (inputB == 'b')
        {
            curriculum3b();
        }
        else
        {
            curriculum3c();
        }
    }
    else if (inputA == 4)
    {
        if (inputB == 'a')
        {
            curriculum4a();
        }
        else if (inputB == 'b')
        {
            curriculum4b();
        }
        else
        {
            curriculum4c();
        }
    }
    else
    {
        if (inputB == 'a')
        {
            curriculum5a();
        }
        else if (inputB == 'b')
        {
            curriculum5b();
        }
        else
        {
            curriculum5c();
        }
    }
}

int main()
{

    char userChoice;
    int mainLoop;

    printf("...............................................................");
    printf("\nWELCOME TO K to 12 GRADE CALCULATOR");
    printf("\n.............................................................");

    do
    {

        semesterChoices();
        printf("\n");
        printf("\nDo you want to calculate grades again?");
        int x = 0;

        printf("\nInstruction: Enter y if you want to continue. If not, enter n: ");
        fflush(stdin);
        fgets(input0, sizeof(input0), stdin);
        inCount = strlen(input0);
        userChoice = input0[0];

        while (!(inCount == 2 && (userChoice == 'y' || userChoice == 'n')))
        {
            printf("\n[Wrong Input] Try Again: ");
            fflush(stdin);
            fgets(input0, sizeof(input0), stdin);
            inCount = strlen(input0);
            userChoice = input0[0];
        }

        if (userChoice == 'y')
        {
            mainLoop = 1;
        }
        else if (userChoice == 'n')
        {
            mainLoop = 0;
        }

    } while (mainLoop == 1);

    printf("\n----------------------------------------------------------------");
    printf("\n[Program developer]");
    printf("\n        Niño Jr Garingarao (2023)");
    printf("\n................................................................");
    printf("\n");
    printf("\nPress any key to Close the program.");
    _getch();
}
