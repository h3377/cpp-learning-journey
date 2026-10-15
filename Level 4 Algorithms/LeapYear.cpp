bool IsleapYear(short Year)
{
    // leap year if perfectly divisible by 400
    
    if (Year % 400 == 0)
    {
        return true;
    }
    // is not leapYear if divisible by 100 
    //but not divisible by 400
    if (Year % 100 == 0)
    {
        return false;
    }

    // leap year if not divisible by 100
    // but divisible by
    if (Year % 4 == 0)
    {
        return true;
    }
    //all other years are not leap year
    else
    {
        return false;
    }
}
