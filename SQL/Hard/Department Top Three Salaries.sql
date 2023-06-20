WITH cte AS(
  SELECT
    e.name as Employee,
    e.salary as Salary,
    d.name as Department,
    DENSE_RANK() OVER(
      PARTITION BY departmentId
      ORDER BY
        salary DESC
    ) AS rnk
  FROM
    Employee e
    JOIN Department d ON e.departmentId = d.id
)
Select
  Department,
  Employee,
  Salary
FROM
  cte
WHERE
  rnk <= 3 # SELECT *
  # FROM cte