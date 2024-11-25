#!/usr/bin/env python3

import cgi
import cgitb

# Enable CGI error reporting
cgitb.enable()

# Print the HTTP headers
print("Content-Type: text/html")    # HTML is following
print()                             # Blank line to end headers

# Start HTML content
print("<html>")
print("<head>")
print("<title>The Importance of Renewable Energy</title>")
print("</head>")
print("<body>")
print("<h1>The Importance of Renewable Energy</h1>")
print("<p>Renewable energy is vital for several reasons:</p>")
print("<ul>")
print("<li><strong>Environmental Benefits:</strong> Reduces greenhouse gas emissions and minimizes air pollution.</li>")
print("<li><strong>Sustainable Development:</strong> Provides a sustainable source of energy that can be replenished naturally.</li>")
print("<li><strong>Energy Security:</strong> Reduces dependence on fossil fuels, contributing to energy independence.</li>")
print("<li><strong>Economic Growth:</strong> Creates jobs in the renewable energy sector and supports local economies.</li>")
print("</ul>")
print("<p>Investing in renewable energy technologies is crucial for a sustainable future.</p>")
print("</body>")
print("</html>")

