require 'matrix'
def calc(n, a, b, c, d)
  p = Array.new(n + 2) do
    Array.new(n + 2)
  end
  p[n + 1][n + 1] = Vector[1, 1, 0]
  (n + 1).times do |i|
    p[i][0]     = Vector[i > 0 ? a[i - 1] : 0, 0, 0]
    p[i][n + 1] = Vector[i > 0 ? b[i - 1] : 0, 1, 0]
    p[0][i]     = Vector[0, i > 0 ? c[i - 1] : 0, 0]
    p[n + 1][i] = Vector[1, i > 0 ? d[i - 1] : 0, 0]
  end
  n.times do |i|
    n.times do |j|
      aa = p[j + 1][0]
      ab = p[j + 1][n + 1] - aa
      cc = p[0][i + 1]
      dd = p[n + 1][i + 1]
      e = (ab.cross_product(cc - aa)).r
      f = (ab.cross_product(dd - aa)).r
      r = e / (e + f)
      p[j + 1][i + 1] = cc + (dd - cc) * r
    end
  end
  (0..n).map do |i|
    (0..n).map do |j|
      p1 = p[i][j]
      v1 = p[i + 1][j] - p1
      v2 = p[i][j + 1] - p1
      v3 = p[i + 1][j + 1] - p1
      ((v3.cross_product(v1)).r + (v3.cross_product(v2)).r) / 2
    end.max
  end.max
end
loop do
  n = gets.to_i
  break if n == 0
  a = gets.split.map(&:to_f)
  b = gets.split.map(&:to_f)
  c = gets.split.map(&:to_f)
  d = gets.split.map(&:to_f)
  puts '%.7f' % calc(n, a, b, c, d)
end
