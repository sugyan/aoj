def cost(x, y)
  sum, c = 0, 0
  while (x > 0 || y > 0)
    xi, yi = x % 10, y % 10
    sum += xi * yi + c
    c = xi + yi + c < 10 ? 0 : 1
    x /= 10
    y /= 10
  end
  sum + c
end
def calc(a, n)
  s, b = [], [], []
  a.each.with_index do |e, i|
    s[i] = Array.new(i) << e
    b[i] = Array.new(i) << 0
  end
  (1 .. n - 1).each do |i|
    (0 .. n - i - 1).each do |j|
      s[j][j + i] = s[j][j + i - 1] + a[j + i];
      min = 1 / 0.0
      (0 .. i - 1).each do |k|
        bb = b[j][j + k] + b[j + k + 1][j + i]
        next if bb >= min
        cost = bb + cost(s[j][j + k], s[j + k + 1][j + i])
        min = cost if cost < min
      end
      b[j][j + i] = min
    end
  end
  b[0][n - 1]
end
1.times do
  n = gets.to_i
  a = gets.split.map(&:to_i)
  puts calc(a, n)
end
