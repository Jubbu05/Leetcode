class MyQueue
{
public:
    stack<int> in;
    stack<int> ot;
    MyQueue()
    {
    }

    void push(int x)
    {
        if (!in.empty())
        {
            while (!in.empty())
            {
                int ele = in.top();
                in.pop();
                ot.push(ele);
            }
        }
        in.push(x);
        if (!ot.empty())
        {
            while (!ot.empty())
            {
                int ele = ot.top();
                ot.pop();
                in.push(ele);
            }
        }
    }

    int pop()
    {
        if (!in.empty())
        {
            int ele = in.top();
            in.pop();
            return ele;
        }
        return -1;
    }

    int peek()
    {
        return in.top();
    }

    bool empty()
    {
        return in.empty() && ot.empty();
    }
};