-- phpMyAdmin SQL Dump
-- version 4.7.1
-- https://www.phpmyadmin.net/
--
-- Host: sql9.freemysqlhosting.net
-- Generation Time: Nov 06, 2020 at 05:03 AM
-- Server version: 5.5.62-0ubuntu0.14.04.1
-- PHP Version: 7.0.33-0ubuntu0.16.04.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `sql9372596`
--

-- --------------------------------------------------------

--
-- Table structure for table `tbl_businesses`
--

CREATE TABLE `tbl_businesses` (
  `business_id` int(100) UNSIGNED NOT NULL,
  `business_name` text NOT NULL,
  `business_description` text NOT NULL,
  `business_streetAddress` text NOT NULL,
  `business_postalCode` varchar(8) NOT NULL,
  `business_city` varchar(100) NOT NULL,
  `business_province` varchar(100) NOT NULL,
  `business_phoneNumber` int(100) NOT NULL,
  `business_email` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_businesses`
--

INSERT INTO `tbl_businesses` (`business_id`, `business_name`, `business_description`, `business_streetAddress`, `business_postalCode`, `business_city`, `business_province`, `business_phoneNumber`, `business_email`) VALUES
(1, 'UWO', 'University', 'Dundas St, South', 'Y7U8I9', 'London', 'Ontario', 555555555, 'info@uwo.ca');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_customers`
--

CREATE TABLE `tbl_customers` (
  `customer_id` int(100) UNSIGNED NOT NULL,
  `customer_username` varchar(100) NOT NULL,
  `customer_phoneNum` bigint(11) NOT NULL,
  `customer_email` varchar(100) NOT NULL,
  `customer_firstName` varchar(100) NOT NULL,
  `customer_lastName` varchar(100) NOT NULL,
  `customer_password` varchar(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_customers`
--

INSERT INTO `tbl_customers` (`customer_id`, `customer_username`, `customer_phoneNum`, `customer_email`, `customer_firstName`, `customer_lastName`, `customer_password`) VALUES
(1, 'abdool86', 0, 'abdool86@gmail.com', 'Abdul', '', '0'),
(3, 'Test', 0, '', 'Testings', '', '0'),
(5, 'sammy', 15196362078, 'sammy@gmail.com', 'Sam', 'Linkln', '0');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_SignInOut`
--

CREATE TABLE `tbl_SignInOut` (
  `SIO_id` int(10) UNSIGNED NOT NULL,
  `SIO_timeIn` tinyint(1) NOT NULL,
  `SIO_timeOut` tinyint(1) NOT NULL,
  `SIO_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `SIO_userID` int(11) NOT NULL,
  `SIO_buisnessID` int(11) NOT NULL,
  `SIO_firstName` varchar(15) NOT NULL,
  `SIO_lastName` varchar(15) NOT NULL,
  `SIO_email` text NOT NULL,
  `SIO_phoneNumber` bigint(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_SignInOut`
--

INSERT INTO `tbl_SignInOut` (`SIO_id`, `SIO_timeIn`, `SIO_timeOut`, `SIO_time`, `SIO_userID`, `SIO_buisnessID`, `SIO_firstName`, `SIO_lastName`, `SIO_email`, `SIO_phoneNumber`) VALUES
(1, 1, 0, '2020-11-06 04:36:19', 1, 1, '', '', '', 0),
(2, 1, 0, '2020-11-06 04:43:36', 0, 1, 'Abdul', 'Hamed', 'hoolio@gmail.com', 5192223333);

-- --------------------------------------------------------

--
-- Table structure for table `tbl_StoreAdmin`
--

CREATE TABLE `tbl_StoreAdmin` (
  `SA_id` int(10) UNSIGNED NOT NULL,
  `SA_businessID` int(10) NOT NULL,
  `SA_adminUserName` varchar(10) NOT NULL,
  `SA_adminPassword` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `tbl_businesses`
--
ALTER TABLE `tbl_businesses`
  ADD PRIMARY KEY (`business_id`);

--
-- Indexes for table `tbl_customers`
--
ALTER TABLE `tbl_customers`
  ADD PRIMARY KEY (`customer_id`);

--
-- Indexes for table `tbl_SignInOut`
--
ALTER TABLE `tbl_SignInOut`
  ADD PRIMARY KEY (`SIO_id`);

--
-- Indexes for table `tbl_StoreAdmin`
--
ALTER TABLE `tbl_StoreAdmin`
  ADD PRIMARY KEY (`SA_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `tbl_businesses`
--
ALTER TABLE `tbl_businesses`
  MODIFY `business_id` int(100) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `tbl_customers`
--
ALTER TABLE `tbl_customers`
  MODIFY `customer_id` int(100) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT for table `tbl_SignInOut`
--
ALTER TABLE `tbl_SignInOut`
  MODIFY `SIO_id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
--
-- AUTO_INCREMENT for table `tbl_StoreAdmin`
--
ALTER TABLE `tbl_StoreAdmin`
  MODIFY `SA_id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
