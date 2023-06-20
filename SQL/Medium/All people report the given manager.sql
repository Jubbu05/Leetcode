SELECT
    e1.employee_id
FROM
    Employee e1
    LEFT JOIN Employee e2 ON e1.manager_id = e2.employee_id
    LEFT JOIN Employee e3 ON e2.manager_id = e3.employee_id
WHERE
    e3.employee_id = 1 -- AND e1.employee_id <> 1
    AND e1.employee_id <> e1.manager_id