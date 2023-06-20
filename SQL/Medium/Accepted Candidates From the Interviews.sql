SELECT c.candidate_id
FROM Rounds r
LEFT JOIN Candidates c 
ON r.interviewe_id = c.interviewe_id
WHERE c.years_of_experience >= 2
GROUP BY c.candidate_id
HAVING SUM(r.score) >= 15