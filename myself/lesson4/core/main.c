extern void SystemInit(void);
int counter = 0;
int main(void)
{
    int *p_int;
    p_int = &counter;
    while (*p_int < 21)
    {
        ++(*p_int); 
    }
		p_int = (int *)0x20000062U;
		*p_int = 0xDEADBEFF;
    return 0;
}

void SystemInit(void)
{
}
