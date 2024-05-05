int sumar(int a, int b);
float multiplicar(float c, float d);
void nada(void);
int restar(int a, int b);


int main()
{
    int _c, _d45, e;
    int 3t = 4;
    signed short int xyz_ = 123;
    unsigned long long int abc = 12345;
    @
    int n = 4, m = 3;
    $
    char arr[] = "this is an array";
    char *p = "this is a pointer";

    float abc = multiplicar(1.5, 2.5);
    int x = 2, y = 3, z = 0;
    z = sumar(1, 2, 3, 4);  //Error cantidad
    z = sumar(1.0, 2.0);    //Error tipo
    z = sumar(3, 4);
    restar(5, 6);
    nada(5);
    sarasa();               //Error, no declarada

    n = m + 1;             //Ok

    return 0;
}

int sumar(int a, int b)
{
    int c = 45;
    return c + b;
}

int restar(int a, int b)
{
    return b - a;
}

char copiar(char str1, char str2)
{
    return "hola";
}

float multiplicar(float a, float b)
{
    return a*b;
}