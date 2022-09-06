SELECT name, count(name) AS count
FROM animal_ins
GROUP BY name
HAVING count(name)>1
ORDER BY name