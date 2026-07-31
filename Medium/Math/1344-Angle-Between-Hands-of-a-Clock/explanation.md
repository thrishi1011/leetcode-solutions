# Angle Between Hands of a Clock

**Difficulty:** Medium | **Language:** cpp

# Angle Between Hands of a Clock

### Approach Summary
The key to solving this problem is to calculate the position of both the hour and minute hands relative to the 12 o'clock position (0 degrees) and then find the absolute difference between them. Since the hour hand moves as the minutes progress, we treat the time as a continuous value rather than discrete integers. By mapping the circle of the clock to 360 degrees, we determine the degree position of the minute hand (6 degrees per minute) and the hour hand (30 degrees per hour, plus an additional 0.5 degrees for every minute passed). The solution then calculates the smaller of the two possible angles (the interior vs. the exterior angle) to satisfy the problem requirements.

### Step-by-step Explanation

1.  **Calculate the Hour Position:** 
    We convert the hour to a decimal format where minutes are represented as a fraction of an hour (`hour + minutes / 60.0`). Because there are 12 hours on a clock face, each hour represents $360 / 12 = 30$ degrees. Multiplying the total hour value by 30 gives us the exact degree position of the hour hand.

2.  **Calculate the Minute Position:**
    Since there are 60 minutes on a clock face, each minute represents $360 / 60 = 6$ degrees. By multiplying the input `minutes` by 6, we get the exact degree position of the minute hand.

3.  **Find the Difference:**
    We calculate the absolute difference between these two degree values. This gives us the angle between the two hands. 

4.  **Normalize the Angle:**
    A clock can form two angles (one clockwise and one counter-clockwise). The problem asks for the "smaller" angle. If our calculated difference is greater than 180 degrees, we subtract it from 360 to find the smaller interior angle. The `min(diff, 360 - diff)` logic ensures we always return the shortest distance between the hands.

*Note: The provided code uses a simplified mathematical formula that combines these steps by normalizing the hour and minute positions relative to a 12-hour cycle and scaling the result by 30.*

### Complexity Analysis

*   **Time Complexity: O(1)**
    The solution performs a constant number of arithmetic operations regardless of the input values. There are no loops or recursion involved.

*   **Space Complexity: O(1)**
    We only use a fixed amount of extra space to store the floating-point variables (`x`, `diff`), meaning the memory usage remains constant regardless of the input.
