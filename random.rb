require 'open-uri'
require "rexml/document"

url = 'http://judge.u-aizu.ac.jp/onlinejudge/'
volume = open(url) do |f|
  f.read.scan(/volumeNo=(\d+)/).flatten.reject{|i| i == '100'}.sample
end

id = open("#{ url }webservice/problem_list?volume=#{ volume }") do |f|
  doc = REXML::Document.new(f)
  doc.elements.to_a('/problem_list/problem').sample.text('id').strip
end

puts "#{ url }description.jsp?id=#{ id }"
