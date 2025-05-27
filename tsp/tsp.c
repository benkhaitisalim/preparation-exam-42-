#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
typedef struct {
    float x;
    float y;
} City;
#define MAX_CITY 11
int num_cities = 0;
City citys[MAX_CITY];
void parsing()
{
    char *line = NULL;
    size_t len = 0;
    while(getline(&line,&len,stdin) != -1 && num_cities < MAX_CITY)
    {
        float x = 0,y = 0;
        float fraction = 0.1f;
        int sing = 0;
        int dicimal = 0;
        int i = 0;
        while(line[i] && line[i] != ',')
        {
            if(line[i] == '-')
            {
                sing = 1;
            }
            else if(line[i] == '.')
            {
                dicimal = 1;
            }
            else if(line[i] >= '0' && line[i] <= '9')
            {
                if(!dicimal)
                {
                    x = x * 10 + (line[i] - '0');
                }
                else 
                {
                    x += (line[i] - '0') * fraction;
                    fraction *= 0.1f;
                }
            }
            i++;
        }
        if(sing == 1)
        {
            x *= -1;
        }
        i++;
        sing = 0;
        fraction = 0.1f;
        dicimal = 0;
        while(line[i] && line[i] != '\n')
        {
            if(line[i] == '-')
            {
                sing = 1;
            }
            else if(line[i] == '.')
            {
                dicimal = 1;
            }
            else if(line[i] >= '0' && line[i] <= '9')
            {
                if(!dicimal)
                {
                    y = (y * 10) + (line[i] - '0');
                }
                else 
                {
                    y += (line[i] - '0') * fraction;
                }
            }
            i++;
        }
        if(sing == 1)
        {
            y *= -1;
        }
        citys[num_cities].x = x;
        citys[num_cities].y = y;
        num_cities++;
    }
    free(line);

}
float distance(City a, City b)
{
    return sqrtf(((a.x - b.x) * (a.x - b.x)) +  ((a.y - b.y) * (a.y - b.y)));
}
void tsp(int visited[], int path[], int level, float cost, float *min_cost) {
    if (level == num_cities) {
        cost += distance(citys[path[level - 1]], citys[path[0]]);
        if (cost < *min_cost) *min_cost = cost;
        return;
    }

    for (int i = 0; i < num_cities; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            path[level] = i;
            tsp(visited, path, level + 1, cost + distance(citys[path[level - 1]], citys[i]), min_cost);
            visited[i] = 0;
        }
    }
}

int main()
{
    parsing();
    if(num_cities < 2)
    {
        return 1;
    }
    float min_cost = 0;
    int i = 0;
    while(i < num_cities - 1)
    {
        min_cost += distance(citys[i], citys[i + 1]);
        i++;
    }
    int visited[MAX_CITY] = {0};
    int path[MAX_CITY] = {0};
    visited[0] = 1;
    tsp(visited,path,1,0.0f,&min_cost);
    printf("%.2f\n", min_cost);
    return 1;
}