<?php
class ParserHelper extends AppHelper {
    function getNicePreview($title, $description) {
        $preview = array();
        if (!empty($title)) {
            array_push($preview, '<strong>' . $this->__trim($title, 15) . '</strong>');
        }
        if (!empty($description)) {
            array_push($preview, $this->__trim($description, 50));
        }
        return implode(' - ', $preview);
    }

    function getStripPreview($string, $length = 25) {
        return $this->__trim(strip_tags($string), $length);
    }

    function getNiceDate($date, $format = 'F j Y h:i A') {
        $dateParts = explode(' ', $date);
        $dateArray = explode('-', $dateParts[0]);
        $timeArray = explode(':', $dateParts[1]);
        return date($format, mktime($timeArray[0], $timeArray[1], $timeArray[2], $dateArray[1], $dateArray[2], $dateArray[0]));
    }

    function __trim($string, $length) {
        if (strlen($string) > $length) {
            return substr($string, 0, $length) . '...';
        } else {
            return $string;
        }
    }

    function makeReadable($title) {
        return low(Inflector::slug($title, '-'));
    }

    function userRole($userRole) {
        switch ($userRole) {
            case 'creator':
                return 'Team Creator';
            case 'member':
                return 'Team Member';
            default:
                return 'Team Member';
        }
    }
}