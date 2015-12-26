def calc(n, c, w)
  a, s, g = [], [], []
  (0 .. n - 1).each do |i|
    s[i] = [0] * n
    (i .. n - 1).each do |j|
      s[i][j] = (j > 0 ? s[i][j - 1] : 0) + w[j]
    end
  end
  (0 .. n - 1).each do |i|
    g[i] = [false] * n
    g[i][i] = true
  end
  (1 .. n - 1).each do |k|
    (0 .. n - k - 1).each do |i|
      j = i + k
      g[i][j] = (g[i][j - 1] && s[i][j - 1] <= c[j]) || (g[i + 1][j] && s[i + 1][j] <= c[i])
    end
  end
  a[0] = 1;
  (1 .. n - 1).each do |i|
    a[i] = g[0][i] ? 1 : a[i - 1] + 1
    (0 .. i - 1).each do |j|
      a[i] = [a[i], a[j] + 1].min if g[j + 1][i]
    end
  end
  a[-1]
end
1.times do
  c, w = [], []
  n = gets.to_i
  n.times do |i|
    c[i], w[i] = gets.split.map(&:to_i)
  end
  puts calc(n, c, w)
end
