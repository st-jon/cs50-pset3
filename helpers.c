// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include "helpers.h"

#define A4 440

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator = atoi(&fraction[0]);
    int denominator = atoi(&fraction[2]);

    int duration = (8 / denominator) * numerator;
    return duration;

}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char note_letter = note[0];
    int octave = atoi(&note[1]);
    int i = 0;
    float freq = 440;
    int key = 0;

    if (strlen(note) == 3)
    {
        i = (note[1] == '#' ? 1 : -1);
        octave = atoi(&note[2]);
    }

    int o = octave - 4;

    freq = freq * pow(2, o);

    freq = freq * pow(2, (i / 12.0));

    switch (note_letter)
    {
        case 'A':
            key = 0;
            break;

        case 'B':
            key = 2;
            break;

        case 'C':
            key = -9;
            break;

        case 'D':
            key = -7;
            break;

        case 'E':
            key = -5;
            break;

        case 'F':
            key = -4;
            break;

        case 'G':
            key = -2;
            break;

        default:
            return true;
    }

    freq = freq * pow(2, (key / 12.0));

    return round(freq);

}


// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


