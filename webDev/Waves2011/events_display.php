<?php
session_start();
include ('common.php');
include('connection.php');
?>
<html>
    <head>
        <title>Event registrations</title>
    </head>
    <body>
        <h2><center>Event registration</center></h2>

        <?php
        if ($_SESSION['login'] == "true") {
            ?>
            <table border="1" style="background: Yellow; color: black;  margin-left: auto; margin-right: auto;">
                <tr>
                    <td>Event</td>
                    <td>Name</td>
                    <td>Email</td>
                    <td>Mobile</td>
                    <td>College</td>
                </tr>
                <?php
                if ($_SESSION['uid'] == 1) {
                    $sql = "SELECT event_registrations.event, users.name, users.email, users.mobile, users.college FROM users RIGHT JOIN event_registrations ON event_registrations.user_id=users.id ORDER BY event_registrations.event";
                    $query = mysql_query($sql); //run query


                    while ($row = mysql_fetch_array($query)) { //iterate through each row of query generated

                        echo "<tr>";



                        echo "<td>";

                        echo $row['event'];

                        echo "</td>";
                        echo "<td>";

                        echo $row['name'];

                        echo "</td>";
                        echo "<td>";

                        echo $row['email'];

                        echo "</td>";
                        echo "<td>";

                        echo $row['mobile'];

                        echo "</td>";
                        echo "<td>";

                        echo $row['college'];

                        echo "</td>";



                        echo "</tr>";
                    }
                }
                else
                    echo "You are not allowed to view this page. }:-[";
            }
            else
                echo "Login to view this page.";
            ?>
        </table>
    </body>
</html>