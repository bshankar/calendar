function isLeapYear (y) {
  if (y % 4 !== 0) return false
  else if (y % 100 !== 0) return true
  else if (y % 400 !== 0) return false
  return true
}

function daysBetweenDates (d1, m1, y1, d2, m2, y2) {
  const daysInMonths = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
  if (m1 === m2 && y1 === y2) return d2 - d1
  if (y1 === y2) {
    if (isLeapYear(y1)) daysInMonths[2] = 29
    return daysInMonths[m1] - d1 + d2 + daysBetweenDates(1, m1 + 1, y1, 1, m2, y2)
  }
  return isLeapYear(y1) ? 366 + daysBetweenDates(d1, m1, y1 + 1, d2, m2, y2) : 365 + daysBetweenDates(d1, m1, y1 + 1, d2, m2, y2)
}

console.log(daysBetweenDates(24, 2, 1996, 21, 9, 2017))
