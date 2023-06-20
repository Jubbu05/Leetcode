SELECT w1.id AS Id
FROM Weather AS w1, Weather AS w2
WHERE w1.temperature > w2.temperature AND DATEDIFF(w1.recordDate, w2.recordDate) = 1

# SELECT wt1.Id 
# FROM Weather wt1, Weather wt2
# WHERE wt1.Temperature > wt2.Temperature AND  TO_DAYS(wt1.DATE)-TO_DAYS(wt2.DATE)=1;