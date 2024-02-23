using namespace std;
#include <iostream>
#include <vector>
#include <stack>
class Solution
{
public:
    std::vector<int> asteroidCollision(std::vector<int> &asteroids)
    {
        stack<int> st; // Stack to simulate collisions

        for (int asteroid : asteroids)
        {
            bool destroyed = false;

            while (!st.empty() && asteroid < 0 && st.top() > 0)
            {
                // Collision occurs
                if (abs(asteroid) > st.top())
                {
                    st.pop(); // Current asteroid destroys asteroid on top of the stack
                }
                else if (abs(asteroid) == st.top())
                {
                    st.pop(); // Both asteroids destroy each other
                    destroyed = true;
                    break; // No need to check further
                }
                else
                {
                    destroyed = true;
                    break; // No collision occurs
                }
            }

            if (!destroyed)
            {
                st.push(asteroid);
            }
        }

        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = result.size() - 1; i >= 0; --i)
        {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};