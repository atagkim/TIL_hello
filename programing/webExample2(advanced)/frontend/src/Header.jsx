import React, { Component } from "react";
import { Navbar, Button, Image } from "react-bootstrap";
import { NavLink } from "react-router-dom";
import axios from "axios";
import $ from "jquery";
import {} from "jquery.cookie";

import ReactHighcharts from 'react-highcharts';

axios.defaults.withCredentials = true;
const headers = { withCredentials: true };

class Header extends Component {
  state = {
    buttonDisplay: "none"
  };

  componentDidMount() {
    if ($.cookie("login_id")) {
      this.setState({
        buttonDisplay: "block"
      });
    } else {
      this.setState({
        buttonDisplay: "none"
      });
    }
  }

  logout = () => {
    axios
      .get("http://localhost:8080/member/logout", {
        headers
      })
      .then(returnData => {
        if (returnData.data.message) {
          $.removeCookie("login_id");
          alert("로그아웃 되었습니다!");
          window.location.href = "/";
        }
      });
  };

  render() {
    const buttonStyle = {
      margin: "0px 0px 0px 10px",
      display: this.state.buttonDisplay,
    };

    return (
      <div style={{textAlign:"center"}}>
        <Navbar>
          <Navbar.Brand 
          href="/" 
          style={{
            marginLeft: window.innerWidth * 0.04,
            fontSize:30,
            fontWeight:"bold"
          }}>

          Today I Learned
          </Navbar.Brand>
          
          <Navbar.Toggle />
          
          <Navbar.Collapse 
          className="justify-content-end" 
          style={{
            marginRight:window.innerWidth * 0.04
            }}>  
            <NavLink to="/mypage">
              <Button style={buttonStyle} variant="primary">
                회원정보 수정
              </Button>
            </NavLink> 
            
            <Button style={buttonStyle} onClick={this.logout} variant="primary">
              로그아웃
            </Button>
          </Navbar.Collapse>

        </Navbar>
        <Image 
        src="./img/tempTitle.png" 
        fluid 
        />
      </div>
    );
  }
}

export default Header;
