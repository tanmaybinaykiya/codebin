<?php
session_start();
include ('common.php');
include('connection.php');
?>
<html>
    <head>
        <title>Accomodation registrations</title>
    </head>
    <body>
        <h2><center>Accomodation registration</center></h2>

        <?php
        if ($_SESSION['login'] == "true") {
            ?>
            <table border="1" style="background: Yellow; color: black;  margin-left: auto; margin-right: auto;">
                <tr>
                    <td>Email</td>
                    <td>Name</td>
                    <td>Mobile</td>
                    <td>College</td>
                    <td>Number of boys</td>
                    <td>Number of girls</td>
                    <td>Arrival date</td>
                    <td>Departure date</td>
                    <td>File name</td>
                    <td>Registration date</td>
                </tr>
                <?php
                if ($_SESSION['uid'] == 1) {
                    $sql = "SELECT users.email, users.name, users.mobile, users.college, accomodation.number_of_boys, accomodation.number_of_girls, accomodation.arrival, accomodation.departure, accomodation.filename, accomodation.Submitted, accomodation.registration_date FROM users RIGHT JOIN accomodation ON accomodation.user_id=users.id ORDER BY accomodation.registration_date";
                    $query = mysql_query($sql); //run query

                    $totalgirls = 0;
                    $totalboys = 0;
                    while ($row = mysql_fetch_array($query)) { //iterate through each row of query generated

                        echo "<tr>";

                        if ($row['Submitted'] == 1) { //only echo those entries that have been submitted

                            echo "<td>";

                            echo $row['email'];

                            echo "</td>";
                            echo "<td>";

                            echo $row['name'];

                            echo "</td>";
                            echo "<td>";

                            echo $row['mobile'];

                            echo "</td>";
                            echo "<td>";

                            echo $row['college'];

                            echo "</td>";
                            echo "<td>";

                            echo $row['number_of_boys'];

                            echo "</td>";
                            echo "<td>";

                            echo $row['number_of_girls'];

                            echo "</td>";
                            echo "<td>";

                            echo $row['arrival'];

                            echo "</td>";
                            echo "<td>";

                            echo $row['departure'];

                            echo "</td>";

                            echo "<td>";

                            echo $row['filename'];

                            echo "</td>";

                            echo "<td>";
                            echo $row['registration_date'];
                            echo "</td>";

                            $totalboys = $totalboys + $row['number_of_boys'];
                            $totalgirls = $totalgirls + $row['number_of_girls'];
                        }

                        echo "</tr>";
                    }
                    echo "<b>Total Girls: </b>";
                    echo $totalgirls;
                    echo " ";
                    echo "<b>Total Boys: </b>";
                    echo $totalboys;
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