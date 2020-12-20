Office Gossip
=============

As any other healthy individual, you love gossip. However, you’ve recently
realised that not all office gossip gets to you. You hadn’t been talking to
Jeff since he shared embarrassing photos of you to everyone in the office.
However, when you finally forgave him, you found out there was a whole world of
gossip completely hidden from you!

Being a sysadmin, you had direct access to HR’s computers. So, determined to
create a better work environment for everyone, you to downloaded the
spreadsheet they use to arrange team building exercises – the list of
colleagues that hate each other. Seeing how massive that spreadsheet really is,
it occurred to you that the reason you were not let in to some of the juiciest
gossips was because of the “wall of hate”. People who hate each other, don’t
tend to share gossip. That means that, if everyone in a group of people hated
the guts of everyone in another group, that could cause gossip bubbles.

Before taking action, you need to plan. You know you will need to make people
talk to each other again, but how many? So, you set yourself to write an
algorithm that will let you know exactly how many people you need to talk into
making amends with someone else.

The input has the following format

```
N
n1 n2 ...
...
n1 n2 ...
```

N is the number of employees in the company. Each line after that represents
one employee and each number within the line represents a colleague they hate.

The output is the least number of people that have to make amends, so the
gossip order is reestablished.

Example input:

```
3
1 2
0
0
2
1
0
```

Example output:

```
2
2
```

In this case we need 0 and either 1 or 2 to make amends. So the number of
people is 2. Same as when there are 2 people who hate each other.
