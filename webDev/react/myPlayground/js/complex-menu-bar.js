var SubMenu = React.createClass({
    getInitialState: function(){
        return { focused: 0 };
    },

    // clicked: function(index){
    //     this.setState({focused: index});
    // },

    render: function() {
        var self = this;
        var subItemDivStyle='sub-item-active';
        // if(this.props.isFocussed){
            
        // }
        return (
            <div className={subItemDivStyle}>{ 
                    this.props.subItems.map(function(subItem, index){
                        return <span key={subItem} /*onClick={self.clicked.bind(self, index)}*/>{subItem}</span>;
                    }) 
                }
            </div>
        );
    }
});

var ComplexMenu = React.createClass({

    getInitialState: function(){
        return { 
            focused: -1,
            hovered: -1
        };
    },

    clicked: function(index){
        clearInterval(this.interval);
        this.setState({
            focused: index
        });        
        var self=this;
        this.interval = setTimeout(function(){
            self.setState({focused: -1})
        }, 2000);
    },

    mouseEnter: function(index){
        this.setState({
            hovered: index
        });
    },

    mouseLeave: function(index){
        console.log('leave')
        var self=this;
        setTimeout(function(){
            self.setState({hovered: -1})
        }, 500);
    },

    render: function() {
        var self = this;
        return (
            <div>{ 
                    this.props.items.map(function(m, index){
                        var style = 'menu-item';
                        var isFocussed = (self.state.focused == index);
                        if(isFocussed){
                            style = 'menu-item menu-item-focussed';
                        }
                        var isHovered=(self.state.hovered == index);
                        if(m.title){
                            if(isHovered || isFocussed){
                                return (
                                    <div className={style} key={m.title} onMouseLeave={self.mouseLeave.bind(self, index)} onClick={self.clicked.bind(self, index)}>
                                        <span>{m.title}</span>
                                        <SubMenu subItems={m.subItems} />
                                    </div>
                                );
                            } else {
                                return (
                                    <div className={style} key={m.title} onMouseEnter={self.mouseEnter.bind(self, index)} onClick={self.clicked.bind(self, index)}>
                                        <span>{m.title}</span>
                                    </div>
                                );
                            }
                        } else{
                            return (
                                <div className={style} key={m} onClick={self.clicked.bind(self, index)}>
                                    <span>{m}</span>
                                </div>
                            );
                        }
                    })
                }
            </div>
        );
    }
});

ReactDOM.render(
    <ComplexMenu items={[
        'Services', 
        {
            title:'Home',
            subItems: ['subItem1', 'subItem2']
        }, 
        { 
            title:'About', 
            subItems: ['subItem']
        }, 
        'Contact us'
    ]} />,
    document.getElementById('complex-menu-bar')
);