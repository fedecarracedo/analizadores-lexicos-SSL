enum week {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday = 10};
double addNumbers(double a, double b);

int main()
{
    int _c, _d45, e;
    int 3t = 4;
    signed short int xyz_ = 123;
    unsigned long long int abc = 12345;
    @
    int n = 4, m = 3;
    int a[n][m];
    int (*p)[m] = a;
    $
    char c = 'a';
    const char c = 'A';
    char arr[] = "this is an array";
    char *p = "this is a pointer";
    const char **cpp;
    long double i j;
    unsigned int = 3);
    static int i = 2;
    enum week today;

    int i = 0, number, count, sum = 0;
    double n1, n2, f_number, f_average, f_sum = 0.0;
    char operation;
    const int maxInput = 100;

    printf("Enter an integer: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("You entered %d.\n", number);
    }

    if (number%2 == 0) {
        printf("%d is an even integer.",number);
    }
    else {
        printf("%d is an odd integer.",number);
    }

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    for(count = 1; count <= num; ++count)
    {
        sum += count;
    }

    while (i <= 5) {
        printf("%d\n", i);
        ++i;
    }

    do {
        printf("Enter a number: ");
        scanf("%lf", &f_number);
        f_sum += f_number;
    }
    while(f_number != 0.0);

    for (i = 1; i <= 10; ++i) {
        printf("Enter n%d: ", i);
        scanf("%lf", &number);

        if (number < 0.0) {
            break;
        }
        else {
            continue;
        }

        sum += number;
    }

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operation);
    printf("Enter two operands: ");
    scanf("%lf %lf",&n1, &n2);

    switch(operation)
    {
        case '+':
            printf("%.1lf + %.1lf = %.1lf",n1, n2, n1+n2);
            break;

        case '-':
            printf("%.1lf - %.1lf = %.1lf",n1, n2, n1-n2);
            break;

        case '*':
            printf("%.1lf * %.1lf = %.1lf",n1, n2, n1*n2);
            break;

        case '/':
            printf("%.1lf / %.1lf = %.1lf",n1, n2, n1/n2);
            break;

        default:
            printf("Error! operator is not correct");
    }

   for (i = 1; i <= maxInput; ++i) {
      printf("%d. Enter a number: ", i);
      scanf("%lf", &f_number);
      
      // go to jump if the user enters a negative number
      if (f_number < 0.0) {
         goto jump;
      }
      f_sum += f_number;
   }

    jump:
        f_average = f_sum / (i - 1);
        printf("Sum = %.2f\n", f_sum);
        printf("Average = %.2f", f_average);

    printf("Enters two numbers: ");
    scanf("%d %d",&n1,&n2);

    sum = addNumbers(n1, n2);
    printf("sum = %d",sum);

    return 0;
}

double addNumbers(double a, double b)
{
    double result;
    result = a+b;
    return result;
}