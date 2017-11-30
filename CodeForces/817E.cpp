#include <bits/stdc++.h>
using namespace std;

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num)
#define read2(num1, num2) scanf("%d%d", &num1, &num2)
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

struct node
{
	int cnt;
	node *left, *right;
};

node *getnode()
{
	node *t = new node;
	t->left = NULL;
	t->right = NULL;
	t->cnt = 0;
	return t;
}

int count(node *t)
{
	if(t==NULL)
		return 0;
	return t->cnt;
}

int main()
{
	node *head, *temp;
	int q, p, l, t, ans;

	head = getnode();

	read(q);
	f(z, q)
	{
		temp = head;
		read(t);

		if(t==1)
		{
			read(p);
			F_(i, 26, -1, 1)
			{
				temp->cnt++;
				if(p & (1<<i))
				{
					if(temp->right == NULL)
						temp->right = getnode();

					temp = temp->right;
				}
				else
				{
					if(temp->left == NULL)
						temp->left = getnode();

					temp = temp->left;
				}
			}

			temp->cnt++;
		}
		else if(t==2)
		{
			read(p);
			F_(i, 26, -1, 1)
			{
				temp->cnt--;
				if(p & (1<<i))
					temp = temp->right;
				else
					temp = temp->left;
			}

			temp->cnt--;
		}
		else
		{
			read2(p, l);
			ans = 0;

			F_(i, 26, -1, 1)
			{
				if(temp == NULL)
					break;
				if(l & (1<<i))
				{
					if(p & (1<<i))
					{
						ans += count(temp->right);
						temp = temp->left;
					}
					else
					{
						ans += count(temp->left);
						temp = temp->right;
					}
				}
				else
				{
					if(p & (1<<i))
						temp = temp->right;
					else
						temp = temp->left;
				}
			}

			printf("%d\n", ans);
		}
	}
}