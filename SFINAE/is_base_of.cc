#include<iostream>
typedef char (&yes)[1]; // see this https://cseweb.ucsd.edu/~ricko/rt_lt.rule.html
typedef char (&no)[2];  // no is the type of ref of size-2 array of char  
// char a[3];
// auto& aa=a;
// int c=sizeof(aa);

template <typename B, typename D>
struct Host
{
    operator B *() const;   // typecasts declaration
    operator D *();
};


template <typename B, typename D>
struct is_base_of
{
    template <typename T>
    static yes check(D *, T);
    static no check(B *, int);

    static const bool value = sizeof(check(Host<B, D>(), int())) == sizeof(yes);
    /*
        https://stackoverflow.com/questions/2910979/how-does-this-implementation-of-the-is-base-of-trait-work
        
        Start with the sizeof(check(Host<B,D>(), int())) part. The compiler can quickly see that this check(...) is a function call expression, 
        so it needs to do overload resolution on check. There are two candidate overloads available, template <typename T> yes check(D*, T); 
        and no check(B*, int);. If the first is chosen, you get sizeof(yes), else sizeof(no)

        Next, let's look at the overload resolution. The first overload is a template instantiation check<int> (D*, T=int) 
        and the second candidate is check(B*, int). The actual arguments provided are Host<B,D> and int(). 
        The second parameter clearly doesn't distinguish them; it merely served to make the first overload a template one. 
        We'll see later why the template part is relevant.

        Now look at the conversion sequences that are needed. 
        For the first overload, we have Host<B,D>::operator D* - one user-defined conversion. 
        For the second, the overload is trickier. We need a B*, but there are possibly two conversion sequences. 
        One is via Host<B,D>::operator B*() const. If (and only if) B and D are related by inheritance will the conversion sequence Host<B,D>::operator D*() + D*->B* exist. 
        Now assume D indeed inherits from B. The two conversion sequences are Host<B,D> -> Host<B,D> const -> operator B* const -> B* and Host<B,D> -> operator D* -> D* -> B*.

        So, for related B and D, no check(<Host<B,D>(), int()) would ambiguous. As a result, the templated yes check<int>(D*, int) is chosen. 
        However, if D does not inherit from B, then no check(<Host<B,D>(), int()) is not ambiguous. 
        At this point, overload resolution cannot happen based on shortest conversion sequence. 
        However, given equal conversion sequences, overload resolution prefers non-template functions, i.e. no check(B*, int).

        You now see why it doesn't matter that the inheritance is private: that relation only serves to eliminate no check(Host<B,D>(), int()) 
        from overload resolution before the access check happens. And you also see why the operator B* const must be const: 
        else there's no need for the Host<B,D> -> Host<B,D> const step, no ambiguity, and no check(B*, int) would always be chosen.
    */ 
};

// Test sample
class Base
{
};
class Derived : private Base
{
};
int main()
{
    std::cout<<is_base_of<Base,Derived>::value;
}